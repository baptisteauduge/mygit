// MyGit Project
//
// mygit_add.h
// File description:
//    mygit_add.h

#ifndef MYGIT_ADD_H
#define MYGIT_ADD_H

/**
 * @brief List all the files added
 *
 * @return char* A string containing all the files added
 */
char *mygit_list_add_str(void);

/**
 * @brief Add a file to the preparation area (aka staging area, i.e. the list of
 * files to commit)
 *
 * @param file The path to the file to add
 * @return int 0 if success, 1 otherwise
 */
int mygit_add(const char *file);

#endif
