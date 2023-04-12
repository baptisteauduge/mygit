// MyGit Project
//
// copy_files.c
// File description:
//    copy_files.c

#include "libs/file/copy_file.h"
#include "libs/file/constants_file.h"
#include <stdio.h>

static int open_file_read_write_and_print_error(const char *path_read,
                                                FILE **file_read,
                                                const char *path_write,
                                                FILE **file_write)
{
  *file_read = fopen(path_read, READ_MODE);
  if (!*file_read)
    return 0;
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

  if (!to || !from ||
      !open_file_read_write_and_print_error(from, &file_from, to, &file_to))
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
