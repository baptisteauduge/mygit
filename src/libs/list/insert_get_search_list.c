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

static void insert_data_in_list_without_duplicate(list_t *new_list,
                                                  list_t *old_list)
{
  cell_t *iter = NULL;

  if (!new_list || !old_list)
    return;
  iter = *old_list;
  while (iter) {
    if (!search_data_in_list(new_list, iter->data))
      create_and_insert_cell_in_list(new_list, iter->data);
  }
}

// Warning: List1 and list2 are not free at the end of the function !
list_t *concat_list_without_duplicate(list_t *list1, list_t *list2)
{
  list_t *new_list = NULL;

  if (!list1 || !list2)
    return NULL;
  new_list = create_init_list();
  if (!new_list)
    return NULL;
  insert_data_in_list_without_duplicate(new_list, list1);
  insert_data_in_list_without_duplicate(new_list, list2);
  return new_list;
}
