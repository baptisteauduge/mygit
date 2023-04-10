// MyGit Project
//
// rights_file.c
// File description:
//    rights_file.c

#include "file/rights_file.h"
#include "file/list_files.h"
#include <stdio.h>

mode_t get_chmod(const char *path)
{
  struct stat ret = {0};

  if (!path || !does_file_exists(path))
    return -1;
  if (stat(path, &ret) == -1)
    return -1;
  return ret.st_mode & 0777;
}

int set_chmod(const char *path, mode_t mode)
{
  if (!path || !does_file_exists(path))
    return 0;
  if (chmod(path, mode) == -1)
    return 0;
  return 1;
}
