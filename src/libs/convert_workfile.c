// Sorbonne University, 2022 - 2023
// MyGit Project
//
// convert_workfile.c
// File description:
//     This file contains the implementation of the functions to convert a
//     workfile in another format.

#include "convert_worktree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *get_content_or_empty_str(const char *str) {
  if (!str)
    return "";
  return str;
}

char *workfile_to_string(const WorkFile *wf) {
  if (!wf)
    return NULL;
  char *res = malloc(sizeof(char) * WORKTREE_FIELD_MAX_SIZE * 3);
  if (!res)
    return NULL;
  snprintf(res, sizeof(char) * WORKTREE_FIELD_MAX_SIZE * 3, "%s\t%s\t%d",
           get_content_or_empty_str(wf->name),
           get_content_or_empty_str(wf->hash), wf->mode);
  return res;
}

WorkFile *string_to_workfile(const char *str) {
  if (!str)
    return NULL;
  char name[WORKTREE_FIELD_MAX_SIZE], hash[WORKTREE_FIELD_MAX_SIZE];
  int mode;
  if (sscanf(str, "%s\t%s\t%d", name, hash, &mode) != 3)
    return NULL;
  WorkFile *res = create_work_file(name);
  if (!res)
    return NULL;
  res->hash = strdup(hash);
  res->mode = mode;
  return res;
}