// MyGit Project
//
// insert_get_search_list.h
// File description:
//    insert_get_search_list.h

#ifndef INSERT_GET_SEARCH_LIST_H
#define INSERT_GET_SEARCH_LIST_H

#define ERROR_INDEX_OUT_OF_RANGE "Error, index out of range\n"

#include "libs/cell/cell.h"
#include "libs/list/list.h"

/**
 * @brief Insert a cell at the begging of the list. The cell is not copied, the
 * pointer is used.
 *
 * @param list The list to modify
 * @param cell The cell to insert
 */
void insert_cell_at_begging_list(list_t *list, cell_t *cell);

/**
 * @brief Create and insert cell in list at the begging of the list.
 * The data is copied in the cell.
 *
 * @param list The list to modify
 * @param data The data to insert
 * @return int 1 if success, 0 if any error occurred
 */
int create_and_insert_cell_in_list(list_t *list, const char *data);

/**
 * @brief Get the the element at the index pos in the list. The index start at
 * 0. If the index is out of range, the function print an error message and
 * return NULL.
 *
 * @param list The list to get the element from
 * @param pos The index of the element to get
 * @return cell_t* The element at the index pos or NULL if the index is out of
 * range
 */
cell_t *get_index_of_list(list_t *list, int pos);

/**
 * @brief Get the the cell which contains the data in the list. The data is
 * compared with the data of the cell. If the data is not found, the function
 * return NULL.
 *
 * @param list The list to get the element from
 * @param data The data to search
 * @return cell_t* The cell which contains the data or NULL if the data is not
 * found
 */
cell_t *search_data_in_list(list_t *list, const char *data);

/**
 * @brief Concat the two list without duplicate. The two list are not modified.
 * The returned list is a new one and must be freed.
 *
 * @param list1 The first list
 * @param list2 The second list
 * @return list_t* The new list or NULL if any error occurred
 */
list_t *concat_list_without_duplicate(list_t *list1, list_t *list2);

#endif