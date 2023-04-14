// MyGit Project
//
// mygit_merge.h
// File description:
//    mygit_merge.h

#ifndef MYGIT_MERGE_H
#define MYGIT_MERGE_H

#include "libs/list/list.h"
#include "libs/work_tree/work_tree.h"

/**
 * @brief Merge two work trees, and return the result. If there is any conflict,
 * the conflicts are stored in the conflicts list and are not present in the
 * result.
 *
 * @param wt1 The first work tree
 * @param wt2 The second work tree
 * @param conflicts The list of conflicts (should be initialized before)
 * @return work_tree_t* The result of the merge (without conflicts)
 */
work_tree_t *mygit_merge_work_trees(work_tree_t *wt1, work_tree_t *wt2,
                                    list_t **conflicts);

#endif
