// MyGit Project
//
// get_content_or_empty_str.c
// File description:
//    get_content_or_empty_str.c

#include "utils/get_content_or_empty_str.h"

const char *get_content_or_empty_str(const char *str)
{
  if (!str)
    return "";
  return str;
}
