// Sorbonne University, 2022 - 2023
// MyGit Project
//
// file_rights.c
// File description:
//     This file contains the implementation of the file rights functions.

#include "file_rights.h"
#include "filesystem.h"
#include <sys/stat.h>

int get_chmod(const char *path) {
  if (!path || !does_file_exists(path))
    return -1;
  struct stat ret;

  if (stat(path, &ret) == -1) {
    return -1;
  }

  return (ret.st_mode & S_IRUSR) | (ret.st_mode & S_IWUSR) |
         (ret.st_mode & S_IXUSR) | /*owner*/
         (ret.st_mode & S_IRGRP) | (ret.st_mode & S_IWGRP) |
         (ret.st_mode & S_IXGRP) | /*group*/
         (ret.st_mode & S_IROTH) | (ret.st_mode & S_IWOTH) |
         (ret.st_mode & S_IXOTH); /*other*/
}

void set_chmod(const char *path, int mode) {
  if (!path || !does_file_exists(path))
    return;
  chmod(path, mode);
}