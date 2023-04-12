// MyGit Project
//
// save_get_file_commit.c
// File description:
//    save_get_file_commit.c

#include "libs/commit/save_get_file_commit.h"
#include "libs/commit/convert_str_commit.h"
#include "libs/file/constants_file.h"
#include "libs/file/read_write_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void save_commit_to_file(commit_t *commit, const char *path)
{
  FILE *file;
  char *commit_str;

  if (!commit || !path)
    return;
  file = fopen(path, WRITE_MODE);
  if (!file)
    return;
  commit_str = convert_commit_to_str(commit);
  if (!commit_str)
    return;
  fprintf(file, "%s\n", commit_str);
  fclose(file);
  free(commit_str);
}

commit_t *get_commit_from_file(const char *path)
{
  char *commit_str = NULL;
  commit_t *commit = NULL;

  if (!path)
    return NULL;
  commit_str = get_file_content(path);
  if (!commit_str)
    return NULL;
  commit = convert_str_to_commit(commit_str);
  free(commit_str);
  return commit;
}