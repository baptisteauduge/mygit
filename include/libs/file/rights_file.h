// MyGit Project
//
// rights_file.h
// File description:
//    rights_file.h

#ifndef RIGHTS_FILE_H
#define RIGHTS_FILE_H

#include <sys/stat.h>

/**
 * @brief Get the chmod of the file (i.e. the rights)
 *
 * @param path The path to the file
 * @return mode_t The modes of the file
 */
mode_t get_chmod(const char *path);

/**
 * @brief Set the chmod of the file (i.e. the rights)
 *
 * @param path The path to the file
 * @param mode The mode to set
 * @return int 1 if the chmod was set, 0 otherwise
 */
int set_chmod(const char *path, mode_t mode);

#endif
