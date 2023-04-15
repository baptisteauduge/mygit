// MyGit Project
//
// mygit_merge.h
// File description:
//    mygit_merge.h

#ifndef MYGIT_MERGE_H
#define MYGIT_MERGE_H

#include "libs/list/list.h"

/**
 * @brief
 * Function that merge the current branch with the remote branch if there is no
 * conflicts if there is conflicts, it will return the list of the conflicted
 * files
 *
 * @param remote_branch the name of the remote branch to merge
 * @param message the message of the merge commit (could be NULL)
 * @return list_t* the list of the conflicted files (if there is, else it will
 * be empty)
 */
list_t *mygit_merge(const char *remote_branch, const char *message);

#endif
