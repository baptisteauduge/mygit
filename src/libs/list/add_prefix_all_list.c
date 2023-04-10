// MyGit Project
//
// add_prefix_all_list.c
// File description:
//    add_prefix_all_list.c

#include "list/add_prefix_all_list.h"
#include "utils/realloc_and_concat.h"
#include <stdlib.h>

void add_prefix_all_list(list_t *list, const char *prefix)
{
  cell_t *iter = NULL;

  if (!list || !prefix)
    return;
  iter = *list;
  while (iter) {
    realloc_and_concat_before(prefix, &iter->data);
    iter = iter->next;
  }
}