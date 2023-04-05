// Sorbonne University, 2022 - 2023
// MyGit Project
//
// list.c
// File description:
//   This file contains the implementation of the list.h header.

#include "list.h"
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

List **create_init_list() {
  List **new = malloc(sizeof(List *));
  if (!new)
    return NULL;
  *new = NULL;
  return new;
}

void free_list(List **list) {
  if (!list)
    return;
  Cell *iter = *list;
  Cell *tmp;
  while (iter) {
    tmp = iter;
    iter = iter->next;
    free_cell(tmp);
  }
  free(list);
}

void insert_cell_at_begging_list(List **list, Cell *cell) {
  if (!list || !cell)
    return;
  cell->next = *list;
  *list = cell;
}

Cell *get_index_of_list(List **list, int pos) {
  if (!list || !*list)
    return NULL;
  Cell *iter = *list;
  for (int i = 0; i < pos && iter; ++i)
    iter = iter->next;
  if (!iter)
    fprintf(stderr, ERROR_INDEX_OUT_OF_RANGE);
  return iter;
}

Cell *search_data_in_list(List **list, const char *str) {
  if (!list || !str)
    return NULL;
  Cell *iter = *list;
  while (iter && strcmp(iter->data, str))
    iter = iter->next;
  return iter;
}

int create_and_insert_cell_in_list(List **list, const char *data) {
  Cell *new_cell = build_cell(data);
  if (!new_cell)
    return 0;
  insert_cell_at_begging_list(list, new_cell);
  return 1;
}
