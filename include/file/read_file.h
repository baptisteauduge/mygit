// MyGit Project
//
// read_file.h
// File description:
//    read_file.h

#ifndef READ_FILE_H
#define READ_FILE_H

char *get_first_line(const char *path);
char *get_file_content(const char *path);
void remove_new_line_if_exists(char *str);

#endif
