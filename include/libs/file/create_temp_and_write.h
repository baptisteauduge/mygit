// MyGit Project
//
// create_temp_and_write.h
// File description:
//    create_temp_and_write.h

#ifndef CREATE_TEMP_AND_WRITE_H
#define CREATE_TEMP_AND_WRITE_H

/**
 * @brief Create a temp file and write in it the content provided
 *
 * @param content The content to write in the file
 * @param tmp_filename The path of the file to create
 * @return int 1 if the file was created and written, 0 otherwise
 */
int create_temp_file_and_write_in_it(char *content, char *tmp_filename);

#endif
