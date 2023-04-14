// MyGit Project
//
// init_refs.h
// File description:
//    init_refs.h

#ifndef INIT_REFS_H
#define INIT_REFS_H

/**
 * @brief Initialize all the required data for a MyGit repository
 *
 */
void init_all(void);

/**
 * @brief Initialize the MyGit directory
 *
 */
void init_mygit(void);

/**
 * @brief Initialize the blobs directory in the MyGit directory
 *
 */
void init_blobs(void);

/**
 * @brief Initialize the refs directory, the HEAD and the default branch in the
 * MyGit directory
 *
 */
void init_refs(void);

/**
 * @brief Initialize the current branch file in the MyGit directory
 *
 */
void init_current_branch(void);

#endif
