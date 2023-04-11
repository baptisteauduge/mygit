// MyGit Project
//
// refs.h
// File description:
//    refs.h

#ifndef REFS_H
#define REFS_H

void create_or_update_ref(const char *ref_name, const char *hash);
void delete_ref(const char *ref_name);
char *get_ref(const char *ref_name);

#endif