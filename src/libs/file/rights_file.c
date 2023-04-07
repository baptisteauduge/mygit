// MyGit Project
//
// rights_file.c
// File description:
//    rights_file.c

#include "file/rights_file.h"
#include "file/list_files.h"
#include <stdio.h>
#include <sys/stat.h>

int get_chmod(const char *path)
{
  struct stat ret = {0};

  if (!path || !does_file_exists(path))
    return -1;
  if (stat(path, &ret) == -1)
    return -1;
  return (ret.st_mode & S_IRUSR) | (ret.st_mode & S_IWUSR) |
         (ret.st_mode & S_IXUSR) | /*owner*/
         (ret.st_mode & S_IRGRP) | (ret.st_mode & S_IWGRP) |
         (ret.st_mode & S_IXGRP) | /*group*/
         (ret.st_mode & S_IROTH) | (ret.st_mode & S_IWOTH) |
         (ret.st_mode & S_IXOTH); /*other*/
}

int set_chmod(const char *path, int mode)
{
  if (!path || !does_file_exists(path))
    return 0;
  chmod(path, mode);
  return 1;
}
