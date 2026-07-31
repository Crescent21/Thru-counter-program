#include <stddef.h>
#include <string.h>
#include <thru-sdk/c/tn_sdk.h>
#include <thru-sdk/c/tn_sdk_syscall.h>
#include "tn_voting_program.h"

static void handle_create_proposal(uchar const *instruction_data, ulong instruction_data_sz TSDK_PARAM_UNUSED) {
    tn_voting_create_proposal_args_t const *args = (tn_voting_create_proposal_args_t const *)instruction_data;

    ushort account_idx = args->account_index;

    uchar const *proof_data = NULL;
    if (args->proof_size > 0) {
        proof_data = instruction_data + sizeof(tn_voting_create_proposal_args_t);
    }

    ulong result = tsys_account_create(account_idx, args->voting_program_seed, proof_data, args->proof_size);
    if (result != TSDK_SUCCESS) {
        tsdk_revert(TN_VOTING_ERR_ACCOUNT_CREATE_FAILED);
    }

    result = tsys_set_account_data_writable(account_idx);
    if (result != TSDK_SUCCESS) {
        tsdk_revert(TN_VOTING_ERR_ACCOUNT_SET_WRITABLE_FAILED);
    }

    result = tsys_account_resize(account_idx, sizeof(tn_voting_proposal_account_t));
    if (result != TSDK_SUCCESS) {
        tsdk_revert(TN_VOTING_ERR_ACCOUNT_RESIZE_FAILED);
    }

    void *account_data = tsdk_get_account_data_ptr(account_idx);
    if (account_data == NULL) {
        tsdk_revert(TN_VOTING_ERR_ACCOUNT_DATA_ACCESS_FAILED);
    }

    tn_voting_proposal_account_t *proposal = (tn_voting_proposal_account_t *)account_data;
    memcpy(proposal->title, args->title, TN_VOTING_TITLE_SZ);
    proposal->yes_votes = 0UL;
    proposal->no_votes = 0UL;
    proposal->voter_count = 0UL;

    tsys_emit_event((uchar const *)proposal->title, TN_VOTING_TITLE_SZ);

    tsdk_return(TSDK_SUCCESS);
}

static void handle_vote(uchar const *instruction_data, ulong instruction_data_sz TSDK_PARAM_UNUSED) {
    tn_voting_vote_args_t const *args = (tn_voting_vote_args_t const *)instruction_data;

    ushort proposal_idx = args->proposal_account_index;
    ushort voter_idx = args->voter_account_index;

    if (args->vote_choice != TN_VOTING_CHOICE_YES && args->vote_choice != TN_VOTING_CHOICE_NO) {
        tsdk_revert(TN_VOTING_ERR_INVALID_VOTE_CHOICE);
    }

    /* Verify the voter account actually signed this transaction */
    if (!tsdk_is_account_authorized_by_idx(voter_idx)) {
        tsdk_revert(TN_VOTING_ERR_NOT_AUTHORIZED);
    }

    void *account_data = tsdk_get_account_data_ptr(proposal_idx);
    if (account_data == NULL) {
        tsdk_revert(TN_VOTING_ERR_ACCOUNT_DATA_ACCESS_FAILED);
    }

    ulong result = tsys_set_account_data_writable(proposal_idx);
    if (result != TSDK_SUCCESS) {
        tsdk_revert(TN_VOTING_ERR_ACCOUNT_SET_WRITABLE_FAILED);
    }

    tn_voting_proposal_account_t *proposal = (tn_voting_proposal_account_t *)account_data;

    tsdk_txn_t const *txn = tsdk_get_txn();
    tn_pubkey_t const *acct_addrs = tsdk_txn_get_acct_addrs(txn);
    tn_pubkey_t const *voter_pubkey = &acct_addrs[voter_idx];

    /* Check for a duplicate vote */
    for (ulong i = 0; i < proposal->voter_count; i++) {
        if (memcmp(&proposal->voters[i], voter_pubkey, sizeof(tn_pubkey_t)) == 0) {
            tsdk_revert(TN_VOTING_ERR_ALREADY_VOTED);
        }
    }

    if (proposal->voter_count >= TN_VOTING_MAX_VOTERS) {
        tsdk_revert(TN_VOTING_ERR_VOTER_LIST_FULL);
    }

    memcpy(&proposal->voters[proposal->voter_count], voter_pubkey, sizeof(tn_pubkey_t));
    proposal->voter_count++;

    if (args->vote_choice == TN_VOTING_CHOICE_YES) {
        proposal->yes_votes++;
    } else {
        proposal->no_votes++;
    }

    tsys_emit_event((uchar const *)&proposal->yes_votes, sizeof(ulong) * 2);

    tsdk_return(TSDK_SUCCESS);
}

TSDK_ENTRYPOINT_FN void start(void) {
    tsdk_txn_t const *txn = tsdk_get_txn();
    uchar const *instruction_data = tsdk_txn_get_instr_data(txn);
    ulong instruction_data_sz = tsdk_txn_get_instr_data_sz(txn);

    if (instruction_data_sz < sizeof(uint)) {
        tsdk_revert(TN_VOTING_ERR_INVALID_INSTRUCTION_DATA_SIZE);
    }

    uint const *instruction_type = (uint const *)instruction_data;

    switch (*instruction_type) {
    case TN_VOTING_INSTRUCTION_CREATE_PROPOSAL:
        if (instruction_data_sz < sizeof(tn_voting_create_proposal_args_t)) {
            tsdk_revert(TN_VOTING_ERR_INVALID_INSTRUCTION_DATA_SIZE);
        }

        tn_voting_create_proposal_args_t const *create_args =
            (tn_voting_create_proposal_args_t const *)instruction_data;

        ulong expected_size =
            sizeof(tn_voting_create_proposal_args_t) + create_args->proof_size;

        if (instruction_data_sz != expected_size) {
            tsdk_revert(TN_VOTING_ERR_INVALID_INSTRUCTION_DATA_SIZE);
        }

        handle_create_proposal(instruction_data, instruction_data_sz);
        break;
    case TN_VOTING_INSTRUCTION_VOTE:
        if (instruction_data_sz != sizeof(tn_voting_vote_args_t)) {
            tsdk_revert(TN_VOTING_ERR_INVALID_INSTRUCTION_DATA_SIZE);
        }

        handle_vote(instruction_data, instruction_data_sz);
        break;
    default:
        tsdk_revert(TN_VOTING_ERR_INVALID_INSTRUCTION_TYPE);
    }

    /* Should never reach here */
    tsdk_revert(TN_VOTING_ERR_INVALID_INSTRUCTION_TYPE);
}
