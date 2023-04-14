// MyGit Project
//
// mygit_handle_args.h
// File description:
//    mygit_handle_args.h

#ifndef MYGIT_HANDLE_ARGS_H
#define MYGIT_HANDLE_ARGS_H

/**
 * @brief The function type of the handle_args functions.
 * The function will handle the arguments of the mygit command.
 */
typedef int (*handle_args_func)(int, char **);

/**
 * @brief Handle the arguments of the mygit command.
 * The function will call the function corresponding to the command.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The return code of the command.
 */
int mygit_handle_args(int argc, char **argv);

#endif
