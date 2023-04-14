// MyGit Project
//
// restore_work_tree.h
// File description:
//    restore_work_tree.h

#ifndef RESTORE_WORK_TREE_H
#define RESTORE_WORK_TREE_H

#include "libs/work_tree/work_tree.h"

/**
 * @brief Restore the work_tree at the given path. All the files in the
 * work_tree are restored. If there is old files with the same name, they are
 * replaced.
 *
 * @param wt The work_tree to restore.
 * @param path The path where the work_tree must be restored. (usually the
 * path of the repository (or ".")
 */
void restore_work_tree(work_tree_t *wt, const char *path);

#endif
