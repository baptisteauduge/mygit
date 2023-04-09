// MyGit Project
//
// create_blob_of_work_tree.c
// File description:
//    create_blob_of_work_tree.c

#include "work_tree/create_blob_of_work_tree.h"
#include "work_tree/convert_str_work_tree.h"
#include "file/constants_file.h"
#include "file/create_blob.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int create_temp_file_and_write_in_it(char *work_tree_str, char *tmp_filename)
{
  int fd = -1;
  FILE *f = NULL;

  if (!work_tree_str)
    return 0;
  fd = mkstemp(tmp_filename);
  if (fd == -1)
    return 0;
  f = fdopen(fd, WRITE_MODE);
  if (!f)
    return 0;
  fprintf(f, "%s", work_tree_str);
  fclose(f);
  return 1;
}

char *create_blob_of_work_tree(work_tree_t *wt)
{
  char *work_tree_str = NULL;
  char tmp_filename[] = "/tmp/XXXXXX";

  if (!wt)
    return NULL;
  work_tree_str = convert_work_tree_to_str(wt);
  if (!work_tree_str)
    return NULL;
  if (!create_temp_file_and_write_in_it(work_tree_str, tmp_filename)) {
    free(work_tree_str);
    return NULL;
  }
  char *hash = create_blob_file_and_get_hash(tmp_filename, ".t");
  free(work_tree_str);
  return hash;
}