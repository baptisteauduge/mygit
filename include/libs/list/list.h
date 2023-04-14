// MyGit Project
//
// list.h
// File description:
//    list.h

#ifndef LIST_H
#define LIST_H

#include "libs/cell/cell.h"

typedef cell_t *list_t;

/**
 * @brief Create a init list (empty list with a NULL pointer)
 *
 * @return list_t*
 */
list_t *create_init_list(void);

/**
 * @brief Free the list and all the cells in the list.
 *
 * @param list The list to free
 */
void free_list(list_t *list);

#endif
