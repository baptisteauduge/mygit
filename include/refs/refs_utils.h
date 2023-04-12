// MyGit Project
//
// refs_utils.h
// File description:
//    refs_utils.h

#ifndef REF_UTILS_H
#define REF_UTILS_H

char *get_hash_from_last_commit_in_branch(const char *branch_name);
void set_head_and_branch_hash_last_commit(const char *branch_name, const char *hash);

#endif