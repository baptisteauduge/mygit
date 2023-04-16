// MyGit Project
//
// commit.c
// File description:
//    commit.c

#include "libs/commit/commit.h"
#include "libs/commit/insert_key_val_in_commit.h"
#include "libs/hash/hash.h"
#include <stdio.h>
#include <stdlib.h>

commit_t *create_and_init_empty_commit(void)
{
  commit_t *commit = malloc(sizeof(commit_t));

  if (!commit)
    return NULL;
  commit->size = 0;
  commit->max_size = COMMIT_KEY_VAL_MAX_SIZE;
  commit->key_val = malloc(sizeof(key_val_t *) * commit->max_size);
  if (!commit->key_val) {
    free(commit);
    return NULL;
  }
  for (size_t i = 0; i < commit->max_size; i++)
    commit->key_val[i] = NULL;
  return commit;
}

commit_t *create_commit_with_tree_key_val(const char *hash)
{
  commit_t *commit;

  if (!hash)
    return NULL;
  commit = create_and_init_empty_commit();
  if (!commit)
    return NULL;
  insert_key_val_in_commit(commit, COMMIT_KEY_HASH, hash);
  return commit;
}

void free_commit(commit_t *commit)
{
  if (!commit)
    return;
  for (size_t i = 0; i < commit->max_size; i++)
    free_key_val(commit->key_val[i]);
  free(commit->key_val);
  free(commit);
}
