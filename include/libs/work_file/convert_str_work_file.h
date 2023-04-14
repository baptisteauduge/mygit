// MyGit Project
//
// convert_str_work_file.h
// File description:
//    convert_str_work_file.h

#ifndef CONVERT_STR_WORK_FILE_H
#define CONVERT_STR_WORK_FILE_H

#define BUFFER_SIZE 1024

#include "libs/work_file/work_file.h"
#include <stddef.h>

/**
 * @brief The size required to store the work_file in a string. The size is
 * calculated with the size of the elements of the work_file and the size of the
 * separator.
 *
 * @param wf The work_file to get the size from.
 * @return size_t The size required to store the work_file in a string.
 */
size_t size_work_file_to_str(const work_file_t *wf);

/**
 * @brief Convert a work_file to a string, the string is allocated and must be
 * freed. The format is "name|hash|mode" where the separator is defined by @ref
 * SEPARATOR_WORK_FILE_STRING constant. If the hash is NULL, the string will
 * contain "name|-|mode". (With a single dash).
 *
 * @param wf The work_file to convert
 * @return char* The string converted or NULL if any error occurred
 */
char *convert_work_file_to_str(const work_file_t *wf);

/**
 * @brief Convert a string to a work_file. The string must be in the format
 * "name|hash|mode" where the separator is defined by @ref
 * SEPARATOR_WORK_FILE_STRING constant. If you want a null hash, you must use
 * have single dash.
 *
 * @param str The string to convert
 * @return work_file_t* The work_file converted or NULL if any error occurred
 */
work_file_t *convert_str_to_work_file(const char *str);

/**
 * @brief Get the content of a string in the format "name|hash|mode" where the
 * separator is defined by @ref SEPARATOR_WORK_FILE_STRING constant. If you want
 * a null hash, you must use have single dash. The name and hash are allocated
 * and must be freed.
 *
 * @param str The string from which you want to extract the content
 * @param name The name extracted from the string (will be allocated)
 * @param hash The hash extracted from the string (will be allocated)
 * @param mode The mode extracted from the string
 * @return int 1 if everything went well, 0 otherwise
 */
int get_content_str_work_file(const char *str, char **name, char **hash,
                              mode_t *mode);

#endif
