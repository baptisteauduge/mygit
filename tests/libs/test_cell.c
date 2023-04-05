// Sorbonne University, 2022 - 2023
// MyGit Project
//
// test_cell.c
// File description:
//     test_cell.c

#include "../../src/libs/cell.h"
#include <stdio.h>

void test_cell(void) { 
  Cell *cell = build_cell("Hello World");
  printf("%s\n", cell_to_string(cell));
  free_cell(cell);
}
