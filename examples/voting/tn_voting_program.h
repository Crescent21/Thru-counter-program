#ifndef TN_VOTING_PROGRAM_H
#define TN_VOTING_PROGRAM_H

#include <thru-sdk/c/tn_sdk.h>

/* Error codes */
#define TN_VOTING_ERR_INVALID_INSTRUCTION_DATA_SIZE (0x2000UL)
#define TN_VOTING_ERR_INVALID_INSTRUCTION_TYPE      (0x2001UL)
#define TN_VOTING_ERR_ACCOUNT_CREATE_FAILED         (0x2002UL)
#define TN_VOTING_ERR_ACCOUNT_SET_WRITABLE_FAILED   (0x2003UL)
#define TN_VOTING_ERR_ACCOUNT_RESIZE_FAILED         (0x2004UL)
#define TN_VOTING_ERR_ACCOUNT_DATA_ACCESS_FAILED    (0x2005UL)
#define TN_VOTING_ERR_NOT_AUTHORIZED                (0x2006UL)
#define TN_VOTING_ERR_ALREADY_VOTED                 (0x2007UL)
#define TN_VOTING_ERR_VOTER_LIST_FULL                (0x2008UL)
#define TN_VOTING_ERR_INVALID_VOTE_CHOICE           (0x2009UL)

/* Instruction types */
#define TN_VOTING_INSTRUCTION_CREATE_PROPOSAL (0U)
#define TN_VOTING_INSTRUCTION_VOTE            (1U)

/* Vote choices */
#define TN_VOTING_CHOICE_NO  (0U)
#define TN_VOTING_CHOICE_YES (1U)

#define TN_VOTING_MAX_VOTERS  (512UL)
#define TN_VOTING_TITLE_SZ    (64UL)

/* Create proposal instruction arguments */
typedef struct __attribute__((packed)) {
    uint instruction_type;
    ushort account_index;
    uchar voting_program_seed[TN_SEED_SIZE];
    uchar title[TN_VOTING_TITLE_SZ];
    uint proof_size;
    /* proof_data follows dynamically based on proof_size */
} tn_voting_create_proposal_args_t;

/* Vote instruction arguments */
typedef struct __attribute__((packed)) {
    uint instruction_type;
    ushort proposal_account_index;
    ushort voter_account_index;
    uchar vote_choice; /* TN_VOTING_CHOICE_YES or TN_VOTING_CHOICE_NO */
} tn_voting_vote_args_t;

/* Proposal account data structure */
typedef struct __attribute__((packed)) {
    uchar title[TN_VOTING_TITLE_SZ];
    ulong yes_votes;
    ulong no_votes;
    ulong voter_count;
    tn_pubkey_t voters[TN_VOTING_MAX_VOTERS];
} tn_voting_proposal_account_t;

#endif
