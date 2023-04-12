// MyGit Project
//
// rights_file.h
// File description:
//    rights_file.h

#ifndef RIGHTS_FILE_H
#define RIGHTS_FILE_H

#include <sys/stat.h>

mode_t get_chmod(const char *path);
int set_chmod(const char *path, mode_t mode);

#endif
