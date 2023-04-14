// MyGit Project
//
// refs.h
// File description:
//    refs.h

#ifndef REFS_H
#define REFS_H

/**
 * @brief Create a or update a ref with the given hash and name.
 *
 * @param ref_name The name of the ref.
 * @param hash The hash of the ref to create or update.
 */
void create_or_update_ref(const char *ref_name, const char *hash);

/**
 * @brief Delete the ref with the given name.
 *
 * @param ref_name The name of the ref.
 * @return int 1 if the ref was deleted, 0 otherwise.
 */
int delete_ref(const char *ref_name);

/**
 * @brief Get a string containing all the refs name and hash of their last
 * commit. Format: "ref_name:hash\nref_name:hash\n..."
 *
 * @return char* The result string or NULL if an error occurred.
 */
char *get_str_all_ref();

/**
 * @brief Get the hash of the ref with the given name.
 *
 * @param ref_name The name of the ref.
 * @return char* The hash of the ref or NULL if an error occurred. (Ex: ref not
 * found)
 */
char *get_ref(const char *ref_name);

#endif