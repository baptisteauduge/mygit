// Sorbonne University, 2022 - 2023
// MyGit Project
// 
// list.h
// File description:
//   This file contains the definition of the List structure and the
//   signatures associated functions.

#ifndef LIST_H
#define LIST_H

#include "cell.h"

typedef Cell List;

/**
 * @brief Function used to create and initialize a list
 * 
 * @return List** 
 */

List **create_init_list();

/**
 * @brief Function used to free a list, if the list is NULL, nothing will be
 * done
 *
 * @param list
 */
void free_list(List **list);

/**
 * @brief Function that will add the provided Cell at the begging of the list
 * provided.
 *
 * @param list
 * @param cell
 */
void insert_cell_at_begging_list(List **list, Cell *cell);

/**
 * @brief Function that return the pos-ème element of the list, or NULL if error
 *
 * @param list
 * @param pos the index of the element you are looking for
 * @return Cell*
 */
Cell *get_index_of_list(List **list, int pos);

/**
 * @brief Search and return (if it exist) the element of the list where data ==
 * str If the element is not in the list, we will return NULL.
 *
 * @param list
 * @param str
 * @return Cell*
 */
Cell *search_data_in_list(List **list, const char *str);

/**
 * @brief Create a cell containing data and add it at the begging of list.
 * The function returns a control, if returned 1, all good.
 *
 * @param list
 * @param data
 * @return int
 */
int create_and_insert_cell_in_list(List **list, const char *data);

#endif
