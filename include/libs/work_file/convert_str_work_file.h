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

size_t size_work_file_to_str(const work_file_t *wf);
char *convert_work_file_to_str(const work_file_t *wf);
work_file_t *convert_str_to_work_file(const char *str);
int get_content_str_work_file(const char *str, char **name, char **hash,
                              mode_t *mode);

#endif
