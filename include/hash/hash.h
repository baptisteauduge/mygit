// MyGit Project
//
// hash.h
// File description:
//    hash.h

#ifndef HASH_H
#define HASH_H

char *get_sha256_of_file(const char *filename);
void put_hash_of_source_in_dest(const char *source, const char *dest);

#endif
