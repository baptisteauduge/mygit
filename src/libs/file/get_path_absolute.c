// MyGit Project
//
// get_path_absolute.c
// File description:
//    get_path_absolute.c

#include <stdlib.h>
#include <string.h>
#include "file/get_path_absolute.h"

char *get_path_absolute(const char *path, const char *filename)
{
  char *path_absolute = NULL;
  size_t size = 0;

  if (!path || !filename)
    return NULL;
  size = strlen(path);
  size += strlen(filename);
  path_absolute = malloc((size + 2) * sizeof(char));
  if (!path_absolute)
    return NULL;
  strcpy(path_absolute, path);
  if (path_absolute[size - 1] != '/')
    strlcat(path_absolute, "/", size + 1);
  strlcat(path_absolute, filename, size + 2);
  return path_absolute;
}
