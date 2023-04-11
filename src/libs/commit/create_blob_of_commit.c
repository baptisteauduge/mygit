// MyGit Project
//
// create_blob_of_commit.c
// File description:
//    create_blob_of_commit.c

#include "commit/create_blob_of_commit.h"
#include "commit/convert_str_commit.h"
#include "file/create_blob.h"
#include "file/create_temp_and_write.h"
#include <stdlib.h>

char *create_blob_of_commit(commit_t *commit) {
  char *commit_str = NULL;
  char tmp_filename[] = "/tmp/XXXXXX";

  if (!commit)
    return NULL;
  commit_str = convert_commit_to_str(commit);
  if (!commit_str)
    return NULL;
  if (!create_temp_file_and_write_in_it(commit_str, tmp_filename)) {
    free(commit_str);
    return NULL;
  }
  char *hash = create_blob_file_and_get_hash(tmp_filename, ".c");
  free(commit_str);
  return hash;
}