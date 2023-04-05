// Sorbonne University, 2022 - 2023
// MyGit Project
//
// file_worktree.c
// File description:
//      This file contains the implementation of the functions used to treat
//      worktrees and files

#include "file_worktree.h"
#include "convert_worktree.h"
#include "filesystem.h"
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

// TODO : Find a way to shorten this function.
char *create_blob_of_worktree(WorkTree *wt) {
  if (!wt)
    return NULL;
  char tmp_filename[] = "/tmp/XXXXXX";
  char dir[3];
  char *tmp;
  char *hash_path;
  char *put_hash_of_source;
  size_t hash_path_size = 0;
  int fd = mkstemp(tmp_filename);
  if (fd == -1)
    return NULL;

  if (worktree_to_file(wt, tmp_filename) == -1)
    goto cleanup;

  put_hash_of_source = get_sha256_of_file(tmp_filename);
  if (!put_hash_of_source)
    goto cleanup;

  memcpy(dir, put_hash_of_source, 2);
  dir[2] = '\0';
  if (!does_file_exists(dir) && mkdir(dir, S_IRWXU) == -1) {
    free(put_hash_of_source);
    goto cleanup;
  }

  hash_path = get_path_from_hash(put_hash_of_source);
  if (!hash_path) {
    free(put_hash_of_source);
    goto cleanup;
  }

  hash_path_size = strlen(hash_path) + 3;
  tmp = malloc(sizeof(char) * hash_path_size);
  if (!tmp) {
    free(put_hash_of_source);
    free(hash_path);
    goto cleanup;
  }

  snprintf(tmp, hash_path_size, "%s.t", hash_path);
  copy_file(tmp, tmp_filename);
  free(hash_path);
  free(tmp);
  close(fd);
  return put_hash_of_source;

cleanup:
  close(fd);
  return NULL;
}
