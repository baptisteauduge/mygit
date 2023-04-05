// Sorbonne University, 2022 - 2023
// MyGit Project
//
// file_rights.h
// File description:
//     This file contains the signatures of the file rights functions.

#ifndef FILE_RIGHTS_H
#define FILE_RIGHTS_H

/**
 * @brief Get the Chmod of a file, return -1 if the file doesn't exist
 *
 * @param path
 * @return int
 */
int get_chmod(const char *path);

/**
 * @brief Set the chmod of a file if the file exist
 *
 * @param path
 * @param mode
 */
void set_chmod(const char *path, int mode);

#endif