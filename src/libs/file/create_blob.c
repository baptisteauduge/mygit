// MyGit Project
//
// create_blob.h
// File description:
//    create_blob.h

#include "file/create_blob.h"
#include "file/constants_file.h"
#include "file/copy_file.h"
#include "file/list_files.h"
#include "hash/hash.h"
#include "utils/realloc_and_concat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

static char *add_prefix_dir(const char *path, const char *dir)
{
  char *path_prefixed = NULL;
  size_t len_path_file = 0;

  path_prefixed = strdup(path);
  if (!path_prefixed)
    return NULL;
  len_path_file = strlen(path);
  if (path_prefixed[0] == '.' && path_prefixed[1] == '/') {
    memmove(path_prefixed, path_prefixed + 2, len_path_file - 1);
    realloc_and_concat_before(dir, &path_prefixed);
    realloc_and_concat_before("./", &path_prefixed);
  }
  else {
    realloc_and_concat_before(dir, &path_prefixed);
  }
  return path_prefixed;
}

char *get_dir_from_hash(const char *hash)
{
  int len_hash = 0;
  char *dir = NULL;
  char *dir_prefixed = NULL;

  if (!hash)
    return NULL;
  len_hash = strlen(hash);
  if (len_hash < 2)
    return NULL;
  dir = calloc(4, sizeof(char));
  if (!dir)
    return NULL;
  dir[0] = hash[0];
  dir[1] = hash[1];
  dir[2] = '/';
  dir_prefixed = add_prefix_dir(dir, DIR_BLOBS);
  if (!dir_prefixed)
    return NULL;
  free(dir);
  return dir_prefixed;
}

char *get_path_from_hash(const char *hash)
{
  int len_hash = 0;
  char *dir = NULL;

  if (!hash)
    return NULL;
  len_hash = strlen(hash);
  dir = calloc(len_hash + 2, sizeof(char));
  if (!dir)
    return NULL;
  dir[0] = hash[0];
  dir[1] = hash[1];
  dir[2] = '/';
  for (int i = 3; i < len_hash + 1; ++i) {
    dir[i] = hash[i - 1];
  }
  realloc_and_concat_before(DIR_BLOBS, &dir);
  return dir;
}

static int get_hash_and_path_with_extension_if_exists(
    const char *path_file, char **hash, char **path, const char *file_extension)
{
  if (!path_file || !does_file_exists(path_file) || !hash || !path)
    return 0;
  *hash = get_sha256_of_file(path_file);
  if (!*hash)
    return 0;
  realloc_and_concat_after(hash, file_extension);
  *path = get_path_from_hash(*hash);
  if (!*path) {
    free(*hash);
    return 0;
  }
  return 1;
}

char *create_blob_file_and_get_hash(const char *path_file,
                                    const char *file_extension)
{
  char *hash = NULL;
  char *path = NULL;
  char *dir = NULL;

  if (!path_file || !does_file_exists(path_file))
    return NULL;
  if (!get_hash_and_path_with_extension_if_exists(path_file, &hash, &path,
                                                  file_extension))
    return NULL;
  dir = get_dir_from_hash(hash);
  if (!dir)
    return NULL;
  if (!does_file_exists(dir))
    mkdir(dir, S_IRWXU);
  if (!copy_file(path, path_file))
    remove(dir);
  free(path);
  free(dir);
  return hash;
}
