// Sorbonne University, 2022 - 2023
// MyGit Project
//
// test_list.c
// File description:
//    test_list.c

#include "test_list.h"
#include "cell/cell.h"
#include "list/convert_str_list.h"
#include "list/insert_get_search_list.h"
#include "list/list.h"
#include "list/save_get_file_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_list(void) {
  list_t *list = create_init_list();
  cell_t *cell1 = build_cell("Hello World 1");
  cell_t *cell2 = build_cell("Hello World 2");
  cell_t *cell3 = build_cell("Hello World 3");
  insert_cell_at_begging_list(list, cell1);
  insert_cell_at_begging_list(list, cell2);
  insert_cell_at_begging_list(list, cell3);
  assert(get_index_of_list(list, 3) == NULL);
  assert(get_index_of_list(list, 0) == cell3);
  assert(search_data_in_list(list, "Hello World 2") == cell2);
  assert(search_data_in_list(list, "Hello World 4") == NULL);
  assert(create_and_insert_cell_in_list(list, "Hello World 4") == 1);
  assert(search_data_in_list(list, "Hello World 4") != NULL);
  char *list_str = list_to_str(list);
  assert(strcmp(list_str,
                "Hello World 4|Hello World 3|Hello World 2|Hello World 1") ==
         0);
  list_t *list2 = str_to_list(list_str);
  assert(list2 != NULL);
  printf("%s\n", get_index_of_list(list2, 0)->data);
  assert(strcmp(get_index_of_list(list2, 0)->data, cell1->data) == 0);
  assert(strcmp(get_index_of_list(list2, 1)->data, cell2->data) == 0);
  assert(strcmp(get_index_of_list(list2, 2)->data, cell3->data) == 0);
  assert(get_index_of_list(list2, 3) != NULL);
  assert(strcmp(get_index_of_list(list2, 3)->data, "Hello World 4") == 0);
  free(list_str);
  free_list(list2);

  save_list_to_file(list, "test_list.txt");
  list_t *list3 = get_list_from_file("test_list.txt");
  assert(list3 != NULL);
  assert(strcmp(get_index_of_list(list3, 0)->data, cell1->data) == 0);
  assert(strcmp(get_index_of_list(list3, 1)->data, cell2->data) == 0);
  assert(strcmp(get_index_of_list(list3, 2)->data, cell3->data) == 0);
  assert(get_index_of_list(list3, 3) != NULL);
  assert(strcmp(get_index_of_list(list3, 3)->data, "Hello World 4") == 0);
  free_list(list3);
  remove("test_list.txt");

  free_list(list);
}