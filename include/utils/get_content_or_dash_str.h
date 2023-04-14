// MyGit Project
//
// get_content_or_dash_str.h
// File description:
//    get_content_or_dash_str.h

#ifndef GET_CONTENT_OR_DASH_STR_H
#define GET_CONTENT_OR_DASH_STR_H

/**
 * @brief Returns the string passed as parameter if it is not NULL, otherwise
 * returns a dash string ("-"). WARNING: the returned string is a static
 * variable, so it should not be freed.
 *
 * @param str The string to check
 * @return const char* The string passed as parameter if it is not NULL,
 * otherwise returns a dash string ("-").
 */
const char *get_content_or_dash_str(const char *str);

#endif