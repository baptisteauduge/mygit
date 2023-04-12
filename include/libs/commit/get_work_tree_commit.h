// MyGit Project
//
// get_work_tree_commit.h
// File description:
//    get_work_tree_commit.h

#ifndef GET_WORK_TREE_COMMIT_H
#define GET_WORK_TREE_COMMIT_H

#include "libs/commit/commit.h"
#include "libs/work_tree/work_tree.h"

work_tree_t *get_work_tree_from_commit(commit_t *commit);

#endif
