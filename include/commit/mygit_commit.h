// MyGit Project
//
// mygit_commit.h
// File description:
//    mygit_commit.h

#ifndef MYGIT_COMMIT_H
#define MYGIT_COMMIT_H

#include "libs/list/list.h"

char *mygit_commit(const char *branch_name, const char *message);
list_t *get_list_all_commits(void);

#endif
