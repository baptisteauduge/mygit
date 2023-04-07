// MyGit Project
//
// read_file.c
// File description:
//    read_file.c

#include "file/read_file.h"
#include "file/constants_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_first_line(const char *path)
{
  FILE *file = NULL;
  char *line = NULL;
  size_t len = 0;
  ssize_t size_read = 0;

  if (!path)
    return NULL;
  file = fopen(path, READ_MODE);
  if (!file)
    return NULL;
  size_read = getline(&line, &len, file);
  if (size_read == -1)
    return NULL;
  fclose(file);
  return line;
}

void remove_new_line_if_exists(char *str)
{
  char *newline = NULL;

  if (!str)
    return;
  newline = strchr(str, '\n');
  if (newline)
    *newline = '\0';
}