// MyGit Project
//
// cell.h
// File description:
//    cell.h

#ifndef CELL_H
#define CELL_H

typedef struct cell_s {
  char *data;
  struct cell_s *next;
} cell_t;

cell_t *build_cell(const char *data);
void free_cell(cell_t *cell);
char *cell_to_string(const cell_t *cell);

#endif
