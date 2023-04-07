// MyGit Project
//
// save_get_file_list.c
// File description:
//    save_get_file_list.c

#include "list/save_get_file_list.h"
#include "file/constants_file.h"
#include "file/read_file.h"
#include "list/convert_str_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void save_list_to_file(list_t *list, const char *path)
{
  FILE *file;
  char *list_str;

  if (!list || !path)
    return;
  file = fopen(path, WRITE_MODE);
  if (!file)
    return;
  list_str = list_to_str(list);
  if (!list_str)
    return;
  fprintf(file, "%s\n", list_str);
  fclose(file);
  free(list_str);
}

list_t *get_list_from_file(const char *path)
{
  char *first_line_file = NULL;
  list_t *list = NULL;

  if (!path)
    return NULL;
  first_line_file = get_first_line(path);
  if (!first_line_file)
    return NULL;
  remove_new_line_if_exists(first_line_file);
  list = str_to_list(first_line_file);
  free(first_line_file);
  return list;
}