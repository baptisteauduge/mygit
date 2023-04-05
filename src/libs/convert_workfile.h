// Sorbonne University, 2022 - 2023
// MyGit Project
//
// convert_workfile.h
// File description:
//     This file contains the signature of the functions to convert a Workfile
//     in another format.

#ifndef CONVERT_WORKFILE_H
#define CONVERT_WORKFILE_H

#include "workfile.h"

/**
 * @brief Convert a WorkFile to a string, each field is separated by
 * tabulation. If one field is NULL, it is replaced by an empty string.
 *
 * @param wf
 * @return char*
 */
char *workfile_to_string(const WorkFile *wf);

/**
 * @brief Convert a string to a WorkFile. All fields must be separated by
 * tabulation.
 *
 * @param str
 * @return WorkFile*
 */
WorkFile *string_to_workfile(const char *str);

#endif