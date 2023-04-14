// MyGit Project
//
// work_file.h
// File description:
//    work_file.h

#ifndef WORK_FILE_H
#define WORK_FILE_H

#define MODE_MAX_SIZE_STR 4
#define TAB_SIZE 1

#include <sys/stat.h>

/**
 * @brief The work_file structure is used to store the information about a file
 * in the working directory.
 *
 * @param name The name of the file (with the relative path from the root of the
 * working dir)
 * @param hash The hash of the file (NULL if the file is not tracked)
 * @param mode The mode of the file (0 if the file is not tracked)
 */
typedef struct work_file_s {
  char *name;
  char *hash;
  mode_t mode;
} work_file_t;

/**
 * @brief Create a work_file_t structure with the given parameters.
 *
 * @param name The name of the file (with the relative path from the root of the
 * working dir)
 * @param hash The hash of the file (NULL if the file is not tracked)
 * @param mode The mode of the file (0 if the file is not tracked)
 * @return work_file_t* The work_file structure created or NULL if any error
 * occurred
 */
work_file_t *create_work_file(const char *name, const char *hash, mode_t mode);

/**
 * @brief Free the memory allocated for the work_file_t structure.
 * The name and hash are freed if they are not NULL.
 *
 * @param wf The work_file to free
 */
void free_work_file(work_file_t *wf);

#endif
