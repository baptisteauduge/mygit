// MyGit Project
//
// commit.c
// File description:
//    commit.c

#include "commit/commit.h"
#include "commit/insert_key_val_in_commit.h"
#include "hash/hash.h"
#include <stdlib.h>

commit_t *create_and_init_empty_commit(void)
{
  commit_t *commit = malloc(sizeof(commit_t));

  if (!commit)
    return NULL;
  commit->key_val = calloc(sizeof(key_val_t *), commit->max_size);
  if (!commit->key_val) {
    free(commit);
    return NULL;
  }
  commit->max_size = COMMIT_KEY_VAL_MAX_SIZE;
  commit->size = 0;
  return commit;
}

commit_t *create_commit_with_tree_key_val(char *hash)
{
  commit_t *commit;

  if (!hash)
    return NULL;
  commit = create_and_init_empty_commit();
  if (!commit)
    return NULL;
  insert_key_val_in_commit(commit, COMMIT_KEY_CONTAINS_HASH, hash);
  return commit;
}

void free_commit(commit_t *commit)
{
  for (size_t i = 0; i < commit->size; i++)
    free_key_val(commit->key_val[i]);
  free(commit->key_val);
  free(commit);
}
