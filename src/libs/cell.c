// Sorbonne University, 2022 - 2023
// MyGit Project
//
// cell.c
// File description:
//     This file contains the implementation of the cell structure.

#include "cell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Cell *build_cell(const char *data) {
  Cell *new_cell = malloc(sizeof(Cell));
  if (!new_cell)
    return NULL;
  new_cell->data = strdup(data);
  if (!new_cell->data) {
    free(new_cell);
    return NULL;
  }
  return new_cell;
}

void free_cell(Cell *cell) {
  if (!cell)
    return;
  free(cell->data);
  free(cell);
}

char *cell_to_string(const Cell *cell) {
  if (!cell)
    return NULL;
  return cell->data;
}
