// MyGit Project
//
// realloc_and_concat.h
// File description:
//    realloc_and_concat.h

#ifndef REALLOC_AND_CONCAT_H
#define REALLOC_AND_CONCAT_H

/**
 * @brief Reallocate the memory of the base string and concatenate the extension
 * string at the end of the base string.
 *
 * @param base The string to concatenate, will be reallocated.
 * @param extension The string to concatenate at the end of the base string.
 */
void realloc_and_concat_after(char **base, const char *extension);

/**
 * @brief Reallocate the memory of the base string and concatenate the prefix
 * string at the beginning of the base string.
 *
 * @param prefix The string to concatenate at the beginning of the base string.
 * @param base The string to concatenate, will be reallocated.
 */
void realloc_and_concat_before(const char *prefix, char **base);

#endif