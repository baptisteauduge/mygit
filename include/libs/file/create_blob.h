// MyGit Project
//
// create_blob.h
// File description:
//    create_blob.h

#ifndef CREATE_BLOB_H
#define CREATE_BLOB_H

/**
 * @brief Get the dir from hash object. The function is based on the
 * @ref MYGIT_DIR_BLOBS constant.
 *
 * @param hash The hash to get the dir from.
 * @return char* The dir. NULL if an error occurred.
 */
char *get_dir_from_hash(const char *hash);

/**
 * @brief Get the path from hash object. The function is based on the
 * @ref MYGIT_DIR_BLOBS constant.
 *
 * @param hash The hash to get the path from.
 * @return char* The path. NULL if an error occurred.
 */
char *get_path_from_hash(const char *hash);

/**
 * @brief Create a blob file in the dir given by the @ref get_path_from_hash
 * function and get hash of the file.
 *
 * @param path_file The path of the file to create the blob from.
 * @param file_extension Optional ! The extension to add to the blob file. (e.g.
 * usually .c for commits, .t for work trees, etc.) If NULL, no extension is
 * added.
 * @return char* The hash of the blob file. NULL if an error occurred.
 */
char *create_blob_file_and_get_hash(const char *path_file,
                                    const char *file_extension);

#endif
