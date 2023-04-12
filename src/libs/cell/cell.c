// MyGit Project
//
// cell.c
// File description:
//    cell.c

#include "libs/cell/cell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

cell_t *build_cell(const char *data)
{
  cell_t *new_cell = NULL;

  if (!data)
    return NULL;
  new_cell = malloc(sizeof(cell_t));
  if (!new_cell)
    return NULL;
  new_cell->data = strdup(data);
  if (!new_cell->data) {
    free(new_cell);
    return NULL;
  }
  return new_cell;
}

void free_cell(cell_t *cell)
{
  if (!cell)
    return;
  free(cell->data);
  free(cell);
}

char *cell_to_string(const cell_t *cell)
{
  if (!cell)
    return NULL;
  return cell->data;
}
