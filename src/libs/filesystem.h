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
List **listdir(char *rootDir);

/**
 * @brief Function that return 1 if the file exist, 0 otherwise
 *
 * @param file
 * @return int
 */
int fileExists(char *file);

/**
 * @brief Function that copy the file from to the file to
 *
 * @param to
 * @param from
 */
void cp(char *to, char *from);

/**
 * @brief Function used to get the path of the file from the hash
 *
 * @param hash
 * @return char*
 */
char *hashToPath(char *hash);

/**
 * @brief Function used to create a blob file from a filename
 *
 * @param filename
 */
void blobFile(char *filename);

#endif
