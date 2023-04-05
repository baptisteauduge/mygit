// Sorbonne University, 2022 - 2023
// MyGit Project
//
// worktree.h
// File description:
//     This file contains the definition of the WorkTree structure and
//     the functions to manipulate it.

#ifndef WORKTREE_H
#define WORKTREE_H

#define WORKTREE_FIELD_MAX_SIZE 256
#define WORKTREE_INIT_SIZE 100

#include "workfile.h"

typedef struct {
  WorkFile *tab;
  int size;
  int n;
} WorkTree;

/**
 * @brief Create and init a WorkTree of size WORKTREE_INIT_SIZE
 *
 * @return WorkTree*
 */
WorkTree *create_init_worktree();

/**
 * @brief Free a WorkTree if it's allocated.
 *
 * @param wt
 */
void free_worktree(WorkTree *wt);

/**
 * @brief Returns the index of the WorkFile in the tab
 * if the "name" is in the WorkTree, else -1.
 *
 * @param wt
 * @param name
 * @return int
 */
int is_in_worktree(const WorkTree *wt, const char *name);

/**
 * @brief Add a WorkFile to the WorkTree if it's not already in.
 *
 * @param wt The WorkTree
 * @param name The name of the new WorkFile
 * @param hash The hash of the new WorkFile
 * @param mode The mode of the new WorkFile
 * @return int 1 if everything went well, 0 if the WorkFile was already in the
 * WorkTree, -1 if an error occured (like if the tab is full).
 */
int append_work_tree_with_values(WorkTree *wt, const char *name,
                                 const char *hash, const int mode);

#endif