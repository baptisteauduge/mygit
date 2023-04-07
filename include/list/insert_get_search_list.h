// MyGit Project
//
// insert_get_search_list.h
// File description:
//    insert_get_search_list.h

#ifndef INSERT_GET_SEARCH_LIST_H
#define INSERT_GET_SEARCH_LIST_H

#define ERROR_INDEX_OUT_OF_RANGE "Error, index out of range\n"

#include "cell/cell.h"
#include "list/list.h"

void insert_cell_at_begging_list(list_t *list, cell_t *cell);
int create_and_insert_cell_in_list(list_t *list, const char *data);
cell_t *get_index_of_list(list_t *list, int pos);
cell_t *search_data_in_list(list_t *list, const char *str);

#endif