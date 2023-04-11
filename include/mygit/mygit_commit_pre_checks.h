// MyGit Project
//
// mygit_commit_pre_checks.h
// File description:
//    mygit_commit_pre_checks.h

#ifndef MYGIT_COMMIT_PRE_CHECKS_H
#define MYGIT_COMMIT_PRE_CHECKS_H

int check_if_refs_exists(void);
int check_if_branch_exists(const char *branch_name);
int check_if_head_is_in_branch(const char *branch_name);

#endif
