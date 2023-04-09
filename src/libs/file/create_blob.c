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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

char *get_dir_from_hash(const char *hash)
{
  int len_hash = 0;
  char *dir = NULL;

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
  return dir;
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
  return dir;
}

// This function is used to add a file extension to a path, path is modified
static void realloc_and_concat(char **base, const char *extension)
{
  char *new_path = NULL;
  size_t len_path = 0;
  size_t len_extension = 0;

  if (!base || !*base || !extension)
    return;
  len_path = strlen(*base);
  len_extension = strlen(extension);
  new_path = realloc(*base, sizeof(char) * (len_path + len_extension + 1));
  if (!new_path)
    return;
  *base = new_path;
  for (size_t i = 0; i < len_extension; ++i) {
    (*base)[len_path + i] = extension[i];
  }
  (*base)[len_path + len_extension] = '\0';
}

static int get_hash_and_path_with_extension_if_exists(
    const char *path_file, char **hash, char **path, const char *file_extension)
{
  if (!path_file || !does_file_exists(path_file) || !hash || !path)
    return 0;
  *hash = get_sha256_of_file(path_file);
  if (!*hash)
    return 0;
  realloc_and_concat(hash, file_extension);
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

  if (!get_hash_and_path_with_extension_if_exists(path_file, &hash, &path,
                                                  file_extension))
    return NULL;
  dir = get_dir_from_hash(hash);
  if (!does_file_exists(dir))
    mkdir(dir, S_IRWXU);
  if (!copy_file(path, path_file))
    remove(dir);
  free(path);
  free(dir);
  return hash;
}
