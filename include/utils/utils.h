// MyGit Project
//
// utils.h
// File description:
//    utils.h

#ifndef UTILS_H
#define UTILS_H

// Constants
#define MYGIT_DIR_RIGTHS 0755
#define MYGIT_FILE_RIGHTS 0755
#define MYGIT_DIR ".mygit/"
#define MYGIT_DIR_BLOBS ".mygit/objects/"
#define MYGIT_DIR_REFS ".mygit/refs"
#define MYGIT_FILE_REF_HEAD "HEAD"
#define MYGIT_DEFAULT_BRANCH "master"
#define MYGIT_PATH_ADD ".mygit/.add"
#define MYGIT_PATH_CURRENT_BRANCH ".mygit/.current_branch"
#define PREFIX_PATH "."

// Log macros
#define LOG_ERROR(...) fprintf(stderr, __VA_ARGS__)
#define LOG_INFO(...) printf(__VA_ARGS__)

#endif
