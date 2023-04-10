// MyGit Project
//
// commit.h
// File description:
//    commit.h

#ifndef COMMIT_H
#define COMMIT_H

#define COMMIT_KEY_VAL_MAX_SIZE 100
#define COMMIT_KEY_CONTAINS_HASH "tree"

#include "key_val/key_val.h"
#include <stddef.h>

typedef struct hash_table_s {
  key_val_t **key_val;
  size_t max_size;
  size_t size;
} hash_table_t;

typedef hash_table_t commit_t;

commit_t *create_and_init_commit(void);
void free_commit(commit_t *commit);

#endif