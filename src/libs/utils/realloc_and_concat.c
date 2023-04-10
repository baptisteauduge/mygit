// MyGit Project
//
// realloc_and_concat.c
// File description:
//    realloc_and_concat.c

#include "utils/realloc_and_concat.h"
#include <stdlib.h>
#include <string.h>

void realloc_and_concat_after(char **base, const char *extension)
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

void realloc_and_concat_before(const char *prefix, char **base)
{
  char *new_path = NULL;
  size_t len_path = 0;
  size_t len_prefix = 0;

  if (!base || !*base || !prefix)
    return;
  len_path = strlen(*base);
  len_prefix = strlen(prefix);
  new_path = malloc(sizeof(char) * (len_path + len_prefix + 1));
  if (!new_path)
    return;
  *base = new_path;
  for (size_t i = 0; i < len_path + len_prefix; ++i) {
    if (i < len_prefix)
      new_path[i] = prefix[i];
    else
      new_path[i] = (*base)[i - len_prefix];
  }
  new_path[len_path + len_prefix] = '\0';
  free(*base);
  *base = new_path;
}