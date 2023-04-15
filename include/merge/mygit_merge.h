// MyGit Project
//
// mygit_merge.h
// File description:
//    mygit_merge.h

#ifndef MYGIT_MERGE_H
#define MYGIT_MERGE_H

/**
 * @brief Function used to merge the provided branch with the current branch.
 * If there is conflits, the function will ask the user to resolve them.
 *
 * @param branch The name of the branch to merge with the current branch.
 * @param message (Optional) The commit deletion message. (Default: "mygit:
 * deletion commit")
 */
void mygit_merge(const char *branch, const char *message);

#endif