// Sorbonne University, 2022 - 2023
// MyGit Project
// 
// hash.h
// File description:
//     This file contains the signatures of the hash.c file.

#ifndef HASH_H
#define HASH_H

/**
 * @brief Function used to hash a file and store the result in another file
 *
 * @param source The source file
 * @param dest The destination file
 */
void put_hash_of_source(const char *source, const char *dest);

/**
 * @brief Function used to hash a file and return the result as a string
 *
 * @param filename The file to hash
 * @return char* The hash of the file
 */
char *get_sha256_of_file(const char *filename);

/**
 * @brief Function used to remove a file with a given path
 *
 * @param filename The filename / path of the file
 */
void remove_file(const char *filename);

#endif