// MyGit Project
//
// copy_files.c
// File description:
//    copy_files.c

#include "libs/file/copy_file.h"
#include "libs/file/constants_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

// Given a file path, create all constituent directories if missing
void create_file_path_dirs(const char *file_path)
{
  char *dir_path = NULL;
  char *next_sep = NULL;
  int dir_path_len = 0;

  if (!file_path)
    return;
  dir_path = calloc(strlen(file_path) + 1, sizeof(char));
  if (!dir_path)
    return;
  next_sep = strchr(file_path, '/');
  while (next_sep) {
    dir_path_len = next_sep - file_path;
    memcpy(dir_path, file_path, dir_path_len);
    dir_path[dir_path_len] = '\0';
    mkdir(dir_path, S_IRWXU | S_IRWXG | S_IROTH);
    next_sep = strchr(next_sep + 1, '/');
  }
  free(dir_path);
}

static int open_file_read_write(const char *path_read, FILE **file_read,
                                const char *path_write, FILE **file_write)
{
  *file_read = fopen(path_read, READ_MODE);
  if (!*file_read)
    return 0;
  create_file_path_dirs(path_write);
  *file_write = fopen(path_write, WRITE_MODE);
  if (!*file_write) {
    fclose(*file_read);
    return 0;
  }
  return 1;
}

int copy_file(const char *to, const char *from)
{
  FILE *file_to = NULL;
  FILE *file_from = NULL;
  int c_read = EOF;

  if (!to || !from || !open_file_read_write(from, &file_from, to, &file_to))
    return 0;
  c_read = fgetc(file_from);
  while (c_read != EOF) {
    if (fputc(c_read, file_to) == EOF) {
      fclose(file_to);
      fclose(file_from);
      return 0;
    }
    c_read = fgetc(file_from);
  }
  fclose(file_to);
  fclose(file_from);
  return 1;
}
