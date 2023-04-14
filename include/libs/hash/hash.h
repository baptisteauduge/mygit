// MyGit Project
//
// hash.h
// File description:
//    hash.h

#ifndef HASH_H
#define HASH_H

/**
 * @brief Get the sha256 of file
 *
 * @param filename The path to the file
 * @return char* The sha256 of the file or NULL if any error occurred
 */
char *get_sha256_of_file(const char *filename);

/**
 * @brief Get the sha256 of the content of the file source and put it in the
 * file dest)
 *
 * @param source The path to the source file
 * @param dest The path to the dest file
 */
void put_hash_of_source_in_dest(const char *source, const char *dest);

/**
 * @brief Hash function used for the commit hash table
 *
 * @param str The string to hash
 * @return unsigned long The hash of the string
 */
unsigned long commit_hash_func(const char *str);

#endif
