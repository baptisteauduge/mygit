// MyGit Project
//
// create_list_branches.h
// File description:
//    create_list_branches.h

#ifndef CREATE_LIST_BRANCHES_H
#define CREATE_LIST_BRANCHES_H

int does_branch_exists(const char *branch);
int create_branch_if_not_exists(const char *branch);
char* get_current_branch(void);

#endif