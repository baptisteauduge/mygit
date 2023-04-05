// Sorbonne University, 2022 - 2023
// MyGit Project
// 
// test_list.c
// File description:
//    test_list.c

#include "test_list.h"
#include "../../src/libs/list.h"
#include "../../src/libs/cell.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


void test_list(void) {
  List **list = create_init_list();
  Cell *cell1 = build_cell("Hello World");
  Cell *cell2 = build_cell("Hello World 2");
  Cell *cell3 = build_cell("Hello World 3");
  insert_cell_at_begging_list(list, cell1);
  insert_cell_at_begging_list(list, cell2);
  insert_cell_at_begging_list(list, cell3);
  assert(get_index_of_list(list, 3) == NULL);
  assert(get_index_of_list(list, 0) == cell3);
  assert(search_data_in_list(list, "Hello World 2") == cell2);
  assert(search_data_in_list(list, "Hello World 4") == NULL);
  assert(create_and_insert_cell_in_list(list, "Hello World 4") == 1);
  assert(search_data_in_list(list, "Hello World 4") != NULL);
  free_list(list);
}