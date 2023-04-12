// MyGit Project
//
// convert_str_commit.c
// File description:
//    convert_str_commit.c

#include "commit/convert_str_commit.h"
#include "commit/commit.h"
#include "commit/insert_key_val_in_commit.h"
#include "key_val/convert_str_key_val.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t get_size_commit_to_str(commit_t *commit)
{
  size_t size_str_commit = 0;
  key_val_t *key_val = NULL;

  if (!commit)
    return 0;
  for (size_t i = 0; i < commit->max_size; ++i) {
    key_val = commit->key_val[i];
    if (key_val)
      size_str_commit += strlen(key_val->key) + strlen(key_val->value) + 2;
  }
  return size_str_commit;
}

static void get_each_key_val_str_and_iter(commit_t *commit, char **str_commit,
                                           size_t size_str_commit)
{
  key_val_t *key_val = NULL;
  char *str_key_val = NULL;

  for (size_t i = 0; i < commit->max_size; ++i) {
    if (!commit->key_val[i])
      continue;
    key_val = commit->key_val[i];
    str_key_val = convert_key_val_to_str(key_val);
    if (!str_key_val)
      return;
    strncat(*str_commit, str_key_val, size_str_commit);
    strncat(*str_commit, "\n", size_str_commit);
    free(str_key_val);
  }
  (*str_commit)[size_str_commit - 1] = '\0';
}

char *convert_commit_to_str(commit_t *commit)
{
  char *str_commit = NULL;
  size_t size_str_commit = 0;

  if (!commit)
    return NULL;
  size_str_commit = get_size_commit_to_str(commit) + 1;
  str_commit = calloc(size_str_commit, sizeof(char));
  if (!str_commit)
    return NULL;
  get_each_key_val_str_and_iter(commit, &str_commit, size_str_commit);
  return str_commit;
}

static void browse_str_and_add_key_val_to_commit(char *str, commit_t *commit)
{
  char *str_key_val = NULL;
  char *str_key = NULL;
  char *str_value = NULL;

  str_key_val = strsep(&str, "\n");
  while (str_key_val) {
    str_key = strsep(&str_key_val, ":");
    str_value = str_key_val;
    insert_key_val_in_commit(commit, str_key, str_value);
    str_key_val = strsep(&str, "\n");
  }
}

commit_t *convert_str_to_commit(const char *str)
{
  commit_t *commit = NULL;
  char *str_copy = NULL;

  if (!str)
    return NULL;
  str_copy = strdup(str);
  if (!str_copy)
    return NULL;
  commit = create_and_init_empty_commit();
  if (!commit)
    return NULL;
  browse_str_and_add_key_val_to_commit(str_copy, commit);
  free(str_copy);
  return commit;
}
