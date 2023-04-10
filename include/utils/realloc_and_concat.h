// MyGit Project
//
// realloc_and_concat.h
// File description:
//    realloc_and_concat.h

#ifndef REALLOC_AND_CONCAT_H
#define REALLOC_AND_CONCAT_H

void realloc_and_concat_after(char **base, const char *extension);
void realloc_and_concat_before(const char *prefix, char **base);

#endif