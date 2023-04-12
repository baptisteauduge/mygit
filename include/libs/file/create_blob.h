// MyGit Project
//
// create_blob.h
// File description:
//    create_blob.h

#ifndef CREATE_BLOB_H
#define CREATE_BLOB_H

char *get_dir_from_hash(const char *hash);
char *get_path_from_hash(const char *hash);
char *create_blob_file_and_get_hash(const char *path_file,
                                    const char *file_extension);

#endif
