// MyGit Project
//
// copy_files.h
// File description:
//    copy_files.h

#ifndef COPY_FILES_H
#define COPY_FILES_H

/**
 * @brief Copy a file from one path to another path. If the destination file
 * already exists, it will be overwritten.
 *
 * @param to The path to copy the file to.
 * @param from The path to copy the file from.
 * @return int 1 if the file was copied successfully, 0 otherwise.
 */
int copy_file(const char *to, const char *from);

#endif
