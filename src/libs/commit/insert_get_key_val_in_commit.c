// MyGit Project
//
// insert_key_val_in_commit.c
// File description:
//    insert_key_val_in_commit.c

#include "commit/insert_key_val_in_commit.h"
#include "hash/hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Insert a key value pair in a commit, using the hash table
// implementation and linear probing to resolve collisions.
void insert_key_val_in_commit(commit_t *commit, const char *key,
                              const char *value)
{
  int hash_key = -1;
  int index_insert = -1;
  key_val_t *new_key_val = NULL;
  int i;

  if (!commit || commit->size >= commit->max_size || !key || !value)
    return;
  hash_key = commit_hash_func(key) % commit->max_size;
  index_insert = hash_key;
  for (i = 0; commit->key_val[index_insert] != NULL; ++i) {
    index_insert = (hash_key + i) % commit->max_size;
  }
  new_key_val = create_key_val(key, value);
  if (!new_key_val)
    return;
  commit->key_val[index_insert] = new_key_val;
  ++(commit->size);
}

// Get the value associated with a key in a commit.
// Using the hash table implementation and linear probing to resolve
// collisions.
char *get_value_from_key_in_commit(commit_t *commit, char *key)
{
  int hash_key = -1;

  if (!commit || !key)
    return NULL;
  hash_key = commit_hash_func(key) % commit->max_size;
  for (size_t i = 0; i < commit->max_size; ++i) {
    if (commit->key_val[hash_key] &&
        !strcmp(commit->key_val[hash_key]->key, key))
      return strdup(commit->key_val[hash_key]->value);
    hash_key = (hash_key + 1) % commit->max_size;
  }
  return NULL;
}
