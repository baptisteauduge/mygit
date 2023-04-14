// MyGit Project
//
// read_write_file.h
// File description:
//    read_write_file.h

#ifndef READ_WRITE_FILE_H
#define READ_WRITE_FILE_H

/**
 * @brief Get the first line of the file
 *
 * @param path The path to the file
 * @return char* The first line of the file or NULL if any error occurred
 */
char *get_first_line(const char *path);

/**
 * @brief Get the content of the file
 *
 * @param path The path to the file
 * @return char* The content of the file or NULL if any error occurred
 */
char *get_file_content(const char *path);

/**
 * @brief Remove the first occurence of the new line character in the string
 *
 * @param str The string to remove the new line character
 */
void remove_new_line_if_exists(char *str);

/**
 * @brief Write the content in the file
 *
 * @param path The path to the file
 * @param content The content to write in the file
 */
void write_file_content(const char *path, const char *content);

#endif
