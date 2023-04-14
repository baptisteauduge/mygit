// MyGit Project
//
// cell.h
// File description:
//    cell.h

#ifndef CELL_H
#define CELL_H

/**
 * @brief A cell is a node in a linked list. It contains a pointer to the next
 * cell, and a pointer to the data contained in the cell.
 *
 * @param data The data contained in the cell
 * @param next The next cell in the linked list
 */
typedef struct cell_s {
  char *data;
  struct cell_s *next;
} cell_t;

/**
 * @brief Build a cell with the data provided, the data is copied in the cell.
 * The next cell is set to NULL.
 *
 * @param data The data to copy in the cell
 * @return cell_t* The cell created, NULL if an error occurred
 */
cell_t *build_cell(const char *data);

/**
 * @brief Free the cell provided. The data contained in the cell is also freed.
 *
 */
void free_cell(cell_t *cell);

/**
 * @brief Convert the cell provided to a string. The string is allocated, and
 * must be freed by the caller.
 *
 * @param cell The cell to convert to a string
 * @return char* The string representing the cell, NULL if an error occurred
 */
char *cell_to_string(const cell_t *cell);

#endif
