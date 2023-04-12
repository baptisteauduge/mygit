// MyGit Project
//
// insert_get_search_list.c
// File description:
//    insert_get_search_list.c

#include "list/insert_get_search_list.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_cell_at_begging_list(list_t *list, cell_t *cell)
{
  if (!list || !cell)
    return;
  cell->next = *list;
  *list = cell;
}

cell_t *get_index_of_list(list_t *list, int pos)
{
  cell_t *iter = NULL;

  if (!list)
    return NULL;
  iter = *list;
  for (int i = 0; i < pos && iter; ++i)
    iter = iter->next;
  if (!iter)
    LOG_ERROR(ERROR_INDEX_OUT_OF_RANGE);
  return iter;
}

cell_t *search_data_in_list(list_t *list, const char *str)
{
  cell_t *iter = NULL;

  if (!list || !str)
    return NULL;
  iter = *list;
  while (iter && strcmp(iter->data, str))
    iter = iter->next;
  return iter;
}

// Returns 0 if error, 1 if success
int create_and_insert_cell_in_list(list_t *list, const char *data)
{
  cell_t *new_cell = NULL;

  if (!list || !data)
    return 0;
  new_cell = build_cell(data);
  if (!new_cell)
    return 0;
  insert_cell_at_begging_list(list, new_cell);
  return 1;
}
