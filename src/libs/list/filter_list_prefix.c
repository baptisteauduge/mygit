// MyGit Project
//
// filter_list_prefix.c
// File description:
//    filter_list_prefix.c

#include "libs/list/filter_list_prefix.h"
#include "libs/list/insert_get_search_list.h"
#include <stdio.h>
#include <string.h>

static int is_prefix(const char *str, const char *pattern)
{
  size_t len_pattern = 0;

  if (!str || !pattern)
    return 0;
  len_pattern = strlen(pattern);
  if (strncmp(str, pattern, len_pattern) == 0)
    return 1;
  return 0;
}

// Return a new list when the data of cell is matching the pattern
// (means that the first chars of data are the same as pattern)
// Warning: the passed list is not freed
list_t *filter_list_prefix(const list_t *list, char *pattern)
{
  list_t *new_list = NULL;
  cell_t *iter = NULL;

  if (!list || !pattern)
    return NULL;
  new_list = create_init_list();
  if (!new_list)
    return NULL;
  iter = *list;
  while (iter) {
    if (is_prefix(iter->data, pattern))
      create_and_insert_cell_in_list(new_list, iter->data);
    iter = iter->next;
  }

  return new_list;
}
