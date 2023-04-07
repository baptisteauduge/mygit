// MyGit Project
//
// list.c
// File description:
//    list.c

#include "list/list.h"
#include <stdio.h>
#include <stdlib.h>

list_t *create_init_list(void)
{
  list_t *new = NULL;

  new = malloc(sizeof(list_t));
  if (!new)
    return NULL;
  *new = NULL;
  return new;
}

void free_list(list_t *list)
{
  cell_t *iter = NULL;
  cell_t *tmp = NULL;

  if (!list)
    return;
  iter = *list;
  while (iter) {
    tmp = iter;
    iter = iter->next;
    free_cell(tmp);
  }
  free(list);
}
