#ifndef HASH_H
#define HASH_H

/**
 * @brief Function used to hash a file and store the result in another file
 * 
 * @param source The source file
 * @param dest The destination file
 */
void hashFile(const char *source, const char *dest);

/**
 * @brief Function used to hash a file and return the result as a string
 * 
 * @param filename The file to hash
 * @return char* The hash of the file
 */
char *sha256file(const char *filename);

/**
 * @brief Function used to remove a file with a given path
 * 
 * @param filename The filename / path of the file
 */
void removeFile(const char *filename);

#endif