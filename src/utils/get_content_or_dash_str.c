// MyGit Project
//
// get_content_or_dash_str.c
// File description:
//    get_content_or_dash_str.c

#include "utils/get_content_or_dash_str.h"

const char *get_content_or_dash_str(const char *str)
{
  if (!str)
    return "-";
  return str;
}
