// MyGit Project
//
// refs_utils.h
// File description:
//    refs_utils.h

#ifndef REF_UTILS_H
#define REF_UTILS_H

/**
 * @brief Get the hash from last commit in branch given in parameter.
 *
 * @param branch_name The name of the branch.
 * @return char* The hash of the last commit in the branch.
 */
char *get_hash_from_last_commit_in_branch(const char *branch_name);

/**
 * @brief Set the head and branch the branch last commit to the given hash.
 *
 * @param branch_name The name of the branch.
 * @param hash The hash of the last commit in the branch.
 */
void set_head_and_branch_hash_last_commit(const char *branch_name,
                                          const char *hash);

#endif