// MyGit Project
//
// create_empty_file.c
// File description:
//    create_empty_file.c

#include "file/create_empty_file.h"
#include "file/constants_file.h"
#include <stdio.h>

void create_empty_file(const char *file_name) {
  if (!file_name)
    return;

  FILE *file = fopen(file_name, WRITE_MODE);
  fclose(file);
}
