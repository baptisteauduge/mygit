// MyGit Project
// 
// list.h
// File description:
//    list.h

#ifndef LIST_H
#define LIST_H

#include "cell/cell.h"

typedef cell_t *list_t;

list_t *create_init_list(void);
void free_list(list_t *list);

#endif
