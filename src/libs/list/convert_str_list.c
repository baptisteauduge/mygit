// MyGit Project
//
// convert_str_list.c
// File description:
//    convert_str_list.c

#include "libs/list/convert_str_list.h"
#include "libs/list/insert_get_search_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t size_list_to_str(list_t *list)
{
  cell_t *iter = NULL;
  size_t size = 0;

  if (!list)
    return 0;
  iter = *list;
  while (iter) {
    size += strlen(cell_to_string(iter));
    iter = iter->next;
    if (iter)
      size += strlen(SEPARATOR_LIST_STRING);
  }
  return size;
}

static void browse_list_and_concat_cells(list_t *list, char *list_str,
                                         size_t str_size)
{
  cell_t *cell = NULL;
  char *cell_str = NULL;

  cell = *list;
  while (cell) {
    cell_str = cell_to_string(cell);
    strlcat(list_str, cell_str, str_size);
    cell = cell->next;
    if (cell)
      strlcat(list_str, SEPARATOR_LIST_STRING, str_size);
  }
}

char *list_to_str(list_t *list)
{
  char *list_str = NULL;
  size_t str_size = 0;

  if (!list)
    return NULL;
  str_size = size_list_to_str(list) + 1;
  list_str = calloc(str_size, sizeof(char));
  if (!list_str)
    return NULL;
  browse_list_and_concat_cells(list, list_str, str_size);
  return list_str;
}

static void separate_str_and_insert_in_list(list_t *list, char **str)
{
  char *token = NULL;

  token = strsep(str, SEPARATOR_LIST_STRING);
  while (token) {
    create_and_insert_cell_in_list(list, token);
    token = strsep(str, SEPARATOR_LIST_STRING);
  }
}

list_t *str_to_list(const char *str)
{
  list_t *list = NULL;
  char *str_copy = NULL;
  char *str_copy_pointer = NULL;

  if (!str)
    return NULL;
  list = create_init_list();
  if (!list)
    return NULL;
  str_copy = strdup(str);
  str_copy_pointer = str_copy;
  if (!str_copy) {
    free_list(list);
    return NULL;
  }
  separate_str_and_insert_in_list(list, &str_copy);
  free(str_copy_pointer);
  return list;
}