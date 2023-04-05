// Sorbonne University, 2022 - 2023
// MyGit Project
//
// convert_worktree.c
// File description:
//     This file contains the implementation of the functions to convert a
//     worktree in another format.

#include "convert_worktree.h"
#include "convert_workfile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *worktree_to_string(const WorkTree *wt) {
  if (!wt)
    return NULL;
  size_t res_size = wt->n * (WORKTREE_FIELD_MAX_SIZE * 3 + 1);
  char *res = malloc(sizeof(char) * res_size), *tmp = NULL;

  if (!res)
    return NULL;
  for (int i = 0; i < wt->n; ++i) {
    tmp = workfile_to_string(wt->tab + i);
    snprintf(res, res_size, "%s%s", res, tmp);
    if (i != wt->n - 1)
      snprintf(res, res_size, "%s\n", res);
    free(tmp);
  }
  return res;
}

WorkTree *string_to_worktree(const char *str) {
  if (!str)
    return NULL;
  int buffer_offset = 0, buffer_size = 0;
  char buffer[WORKTREE_FIELD_MAX_SIZE * 3];
  WorkFile *tmp = NULL;
  WorkTree *res = create_init_worktree();
  if (!res)
    return NULL;

  for (int i = 0; str[i] != '\0'; ++i) {
    if (str[i] == '\n') {
      memcpy(buffer, str + buffer_offset, buffer_size * sizeof(char));
      buffer[buffer_size] = '\0';
      tmp = string_to_workfile(buffer);
      if (!tmp) {
        fprintf(stderr, "Error, when creating a new workfile, the returned "
                        "WorkTree could be uncomplete\n");
        return res;
      }
      if (!append_work_tree_with_values(res, tmp->name, tmp->hash, tmp->mode)) {
        fprintf(stderr, "Error when trying to append the WorkTree, WorkTree "
                        "could be uncomplete\n");
        free_work_file(tmp);
        return res;
      }
      buffer_offset += buffer_size + 1;
      buffer_size = 0;
      free_work_file(tmp);
      continue;
    }
    ++buffer_size;
  }
  memcpy(buffer, str + buffer_offset, buffer_size * sizeof(char));
  buffer[buffer_size] = '\0';
  tmp = string_to_workfile(buffer);
  if (!tmp) {
    fprintf(stderr, "Error, when creating a new workfile, the returned "
                    "WorkTree could be uncomplete\n");
    return res;
  }
  if (!append_work_tree_with_values(res, tmp->name, tmp->hash, tmp->mode)) {
    fprintf(stderr, "Error when trying to append the WorkTree, WorkTree could "
                    "be uncomplete\n");
    free_work_file(tmp);
    return res;
  }
  free_work_file(tmp);
  return res;
}

int worktree_to_file(const WorkTree *wt, const char *file) {
  if (!wt || !file)
    return -1;
  FILE *f = fopen(file, "w");
  if (!f)
    return -1;
  char *worktree_str = worktree_to_string(wt);
  if (!worktree_str) {
    fclose(f);
    return -1;
  }
  fprintf(f, "%s", worktree_str);
  fclose(f);
  free(worktree_str);
  return 0;
}

WorkTree *file_to_worktree(const char *file) {
  if (!file)
    return NULL;
  char file_content[WORKTREE_FIELD_MAX_SIZE * 3 * WORKTREE_INIT_SIZE];
  char buffer[WORKTREE_FIELD_MAX_SIZE * 3];
  FILE *f = fopen(file, "r");

  if (!f) {
    fprintf(stderr, "Error, can't open the file %s in read mode", file);
    return NULL;
  }

  while (fgets(buffer, WORKTREE_FIELD_MAX_SIZE * 3, f))
    snprintf(file_content, WORKTREE_FIELD_MAX_SIZE * 3 * WORKTREE_INIT_SIZE,
             "%s%s", file_content, buffer);
  fclose(f);
  return string_to_worktree(file_content);
}