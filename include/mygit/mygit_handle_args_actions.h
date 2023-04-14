// MyGit Project
//
// mygit_handle_args_actions.h
// File description:
//    mygit_handle_args_actions.h

#ifndef MYGIT_HANDLE_ARGS_ACTIONS_H
#define MYGIT_HANDLE_ARGS_ACTIONS_H

/**
 * @brief Handle the arguments of the init command.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The return code of the command.
 */
int init_handle_args(int argc, char **argv);

/**
 * @brief Handle the arguments of the list-refs command.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The return code of the command.
 */
int list_refs_handle_args(int argc, char **argv);

/**
 * @brief Handle the arguments of the create-ref command.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The return code of the command.
 */
int create_ref_handle_args(int argc, char **argv);

/**
 * @brief Handle the arguments of the delete-ref command.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The return code of the command.
 */
int delete_ref_handle_args(int argc, char **argv);

/**
 * @brief Handle the arguments of the add command.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The return code of the command.
 */
int add_handle_args(int argc, char **argv);

/**
 * @brief Handle the arguments of the list-add command.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The return code of the command.
 */
int list_add_handle_args(int argc, char **argv);

/**
 * @brief Handle the arguments of the clear-add command.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The return code of the command.
 */
int clear_add_handle_args(int argc, char **argv);

/**
 * @brief Handle the arguments of the commit command.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The return code of the command.
 */
int commit_handle_args(int argc, char **argv);

/**
 * @brief Handle the arguments of the current-branch command.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The return code of the command.
 */
int current_branch_handle_args(int argc, char **argv);

/**
 * @brief Handle the arguments of the branch command.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The return code of the command.
 */
int branch_handle_args(int argc, char **argv);

/**
 * @brief Handle the arguments of the branch-print command.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The return code of the command.
 */
int branch_print_handle_args(int argc, char **argv);

/**
 * @brief Handle the arguments of the checkout-branch command.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The return code of the command.
 */
int checkout_branch_handle_args(int argc, char **argv);

/**
 * @brief Handle the arguments of the checkout-commit command.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The return code of the command.
 */
int checkout_commit_handle_args(int argc, char **argv);

#endif