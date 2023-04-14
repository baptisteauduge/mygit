// MyGit Project
//
// get_path_absolute.h
// File description:
//    get_path_absolute.h

#ifndef GET_PATH_ABSOLUTE_H
#define GET_PATH_ABSOLUTE_H

/**
 * @brief Get the path absolute from a path and a filename
 * (The function allocates memory and returns path/filename)
 *
 * @param path The path to the file
 * @param filename The name of the file
 * @return char* The path absolute
 */
char *get_path_absolute(const char *path, const char *filename);

#endif
