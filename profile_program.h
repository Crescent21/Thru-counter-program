#ifndef PROFILE_PROGRAM_H
#define PROFILE_PROGRAM_H

#include <thru-sdk/c/tn_sdk.h>

typedef struct __attribute__((packed)) {
    char name[32];
    char username[32];
    char bio[128];
} profile_account_t;

#endif
