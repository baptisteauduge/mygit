// MyGit Project
//
// create_blob_of_work_tree.c
// File description:
//    create_blob_of_work_tree.c

#include "libs/work_tree/create_blob_of_work_tree.h"
#include "libs/work_tree/convert_str_work_tree.h"
#include "libs/file/constants_file.h"
#include "libs/file/create_blob.h"
#include "libs/file/create_temp_and_write.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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