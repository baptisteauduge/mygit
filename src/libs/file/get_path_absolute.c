// MyGit Project
//
// get_path_absolute.c
// File description:
//    get_path_absolute.c

#include "libs/file/get_path_absolute.h"
#include <stdlib.h>
#include <string.h>

char *get_path_absolute(const char *path, const char *filename)
{
  char *path_absolute = NULL;
  size_t size = 0;

  if (!path || !filename)
    return NULL;
  size = strlen(path);
  size += strlen(filename);
  path_absolute = calloc((size + 2), sizeof(char));
  if (!path_absolute)
    return NULL;
  strcpy(path_absolute, path);
  if (path_absolute[size - 1] != '/')
    strncat(path_absolute, "/", size + 1);
  strncat(path_absolute, filename, size + 2);
  return path_absolute;
}
