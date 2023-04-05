// Sorbonne University, 2022 - 2023
// MyGit Project
//
// cell.h
// File description:
//     This file contains the declaration of the cell structure.
//     And the signature of the functions used to manipulate it.

#ifndef CELL_H
#define CELL_H

typedef struct cell {
  char *data;
  struct cell *next;
} Cell;

/**
 * @brief Function used to build a new Cell, will return NULL if any error
 * The provided data will be copied
 *
 * @param data
 * @return Cell*
 */
Cell *build_cell(const char *data);

/**
 * @brief Function used to free a cell, if the cell is NULL, nothing will be
 * done
 *
 * @param cell
 */
void free_cell(Cell *cell);

/**
 * @brief Cell to string
 *
 * @param cell
 * @return char*
 */
char *cell_to_string(const Cell *cell);

#endif
