// MyGit Project
//
// read_write_file.c
// File description:
//    read_write_file.c

#include "libs/file/read_write_file.h"
#include "libs/file/constants_file.h"
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

static void realloc_and_strcat(char **content, ssize_t size_read, char **line)
{
  size_t size_content = 0;

  if (!content || !line || !*line)
    return;
  if (!*content)
    *content = strdup(*line);
  else {
    size_content = strlen(*content);
    *content = realloc(*content, size_content + size_read + 1);
    if (!*content)
      return;
    strncat(*content, *line, size_content + size_read + 1);
  }
  free(*line);
  *line = NULL;
}

char *get_file_content(const char *path)
{
  FILE *file = NULL;
  char *content = NULL;
  char *line = NULL;
  size_t len = 0;
  ssize_t size_read = 0;

  if (!path)
    return NULL;
  file = fopen(path, READ_MODE);
  if (!file)
    return NULL;
  size_read = getline(&line, &len, file);
  if (size_read == -1 && line) {
    fclose(file);
    free(line);
    return NULL;
  }
  while (size_read != -1) {
    realloc_and_strcat(&content, size_read, &line);
    size_read = getline(&line, &len, file);
  }
  free(line);
  fclose(file);
  return content;
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

void write_file_content(const char *path, const char *content)
{
  FILE *file = NULL;

  if (!path || !content)
    return;
  file = fopen(path, WRITE_MODE);
  if (!file)
    return;
  fputs(content, file);
  fclose(file);
}
