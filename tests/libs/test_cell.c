// MyGit Project
//
// test_cell.c
// File description:
//     test_cell.c

#include "cell/cell.h"
#include <stdio.h>

void test_cell(void) { 
  cell_t *cell = build_cell("Hello World");
  printf("%s\n", cell_to_string(cell));
  free_cell(cell);
}
