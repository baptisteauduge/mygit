// MyGit Project
//
// insert_key_val_in_commit.h
// File description:
//    insert_key_val_in_commit.h

#ifndef INSERT_KEY_VAL_IN_COMMIT_H
#define INSERT_KEY_VAL_IN_COMMIT_H

#include "libs/commit/commit.h"

void insert_key_val_in_commit(commit_t *commit, const char *key,
                              const char *value);
char *get_value_from_key_in_commit(commit_t *commit, char *key);

#endif
