#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include "list.h"

/**
 * @brief Function that return a list of all the files and directories in the
 * directory rootDir
 *
 * @param rootDir
 * @return List**
 */
List **listdir(const char *rootDir);

/**
 * @brief Function that return 1 if the file exist, 0 otherwise
 *
 * @param file
 * @return int
 */
int fileExists(const char *file);

/**
 * @brief Function that copy the file from to the file to
 *
 * @param to
 * @param from
 */
void cp(const char *to, const char *from);

/**
 * @brief Function used to get the path of the file from the hash
 *
 * @param hash
 * @return char*
 */
char *hashToPath(const char *hash);

/**
 * @brief Function used to create a blob file from a filename
 *
 * @param filename
 */
void blobFile(const char *filename);

/**
 * @brief Get the Chmod of a file, return -1 if the file doesn't exist
 *
 * @param path
 * @return int
 */
int getChmod(const char *path);

/**
 * @brief Set the chmod of a file if the file exist
 *
 * @param path
 * @param mode
 */
void setChmod(const char *path, int mode);

#endif
