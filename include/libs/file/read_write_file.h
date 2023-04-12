// MyGit Project
//
// read_write_file.h
// File description:
//    read_write_file.h

#ifndef READ_WRITE_FILE_H
#define READ_WRITE_FILE_H

char *get_first_line(const char *path);
char *get_file_content(const char *path);
void remove_new_line_if_exists(char *str);
void write_file_content(const char *path, const char *content);

#endif
