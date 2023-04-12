// MyGit Project
//
// get_branch_commit_tree.h
// File description:
//    get_branch_commit_tree.h

#ifndef GET_BRANCH_COMMIT_TREE_H
#define GET_BRANCH_COMMIT_TREE_H

#include "libs/list/list.h"

char *get_branch_commits_tree_str(const char *branch_name);
void print_branch_commit_tree(char *branch);
list_t *get_commit_from_branch_list(const char *branch_name);

#endif
