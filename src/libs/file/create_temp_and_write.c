// MyGit Project
//
// create_temp_and_write.c
// File description:
//    create_temp_and_write.c

#include "file/create_temp_and_write.h"
#include "file/constants_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int create_temp_file_and_write_in_it(char *content, char *tmp_filename)
{
  int fd = -1;
  FILE *f = NULL;

  if (!content)
    return 0;
  fd = mkstemp(tmp_filename);
  if (fd == -1)
    return 0;
  f = fdopen(fd, WRITE_MODE);
  if (!f)
    return 0;
  fprintf(f, "%s", content);
  fclose(f);
  return 1;
}