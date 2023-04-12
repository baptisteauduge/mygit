## MyGit Project
##
## Makefile
## File description:
## Makefile for MyGit project

SRC						=						src/libs/cell/cell.c															\
													src/libs/list/convert_str_list.c									\
													src/libs/list/insert_get_search_list.c						\
													src/libs/list/list.c															\
													src/libs/list/save_get_file_list.c								\
													src/libs/list/add_prefix_all_list.c								\
													src/libs/file/read_write_file.c										\
													src/libs/file/copy_file.c													\
													src/libs/file/create_blob.c												\
													src/libs/file/list_files.c												\
													src/libs/file/rights_file.c												\
													src/libs/file/get_path_absolute.c									\
													src/libs/file/create_temp_and_write.c							\
													src/libs/file/create_empty_file.c									\
													src/libs/hash/hash.c															\
													src/libs/work_file/work_file.c										\
													src/libs/work_file/convert_str_work_file.c				\
													src/libs/work_tree/work_tree.c										\
													src/libs/work_tree/convert_str_work_tree.c				\
													src/libs/work_tree/insert_get_search_work_tree.c	\
													src/libs/work_tree/save_get_file_work_tree.c			\
													src/libs/work_tree/create_blob_of_work_tree.c			\
													src/libs/work_tree/save_content_and_work_tree.c 	\
													src/libs/work_tree/restore_work_tree.c 						\
													src/libs/utils/realloc_and_concat.c								\
													src/libs/utils/get_content_or_dash_str.c					\
													src/libs/key_val/key_val.c												\
													src/libs/key_val/convert_str_key_val.c						\
													src/libs/commit/commit.c													\
													src/libs/commit/insert_get_key_val_in_commit.c 		\
													src/libs/commit/convert_str_commit.c							\
													src/libs/commit/save_get_file_commit.c						\
													src/libs/commit/create_blob_of_commit.c						\
													src/init/init.c																		\
													src/refs/refs.c																		\
													src/refs/refs_utils.c															\
													src/mygit/mygit_handle_args.c											\
													src/mygit/mygit_handle_args_actions.c							\
													src/mygit/mygit_add.c															\
													src/mygit/mygit_commit.c													\
													src/mygit/mygit_commit_pre_check.c								\
													src/branch/create_list_branches.c									\
													src/branch/get_branch_commit_tree.c


OBJ						=						$(SRC:.c=.o)

OBJ_TEST			=						$(SRC_TEST:.c=.o)

NAME					=						mygit.out

TEST_NAME			=						unit_tests

CC						=						gcc

CFLAGS				=						-Wall -Wextra -Werror

CPPFLAGS			=						-I./include 

all: $(NAME)

$(NAME): $(OBJ) main.o
	$(CC) -o $(NAME) $(CFLAGS) $(CPPFLAGS) $(OBJ) main.o

tests: $(OBJ) tests.o
	$(CC) -o $(TEST_NAME) $(CPPFLAGS) $(CFLAGS) $(OBJ) tests.o -lcriterion --coverage


main.o: src/main.c
	gcc -c $(CFLAGS) $(CPPFLAGS) src/main.c

tests.o: tests/tests.c
	gcc -c $(CFLAGS) $(CPPFLAGS) tests/tests.c

clean:
	$(RM) $(OBJ) $(OBJ_TEST) src/main.o tests/test.o

fclean: clean
	$(RM) $(NAME) unit_tests tests.o tests.gcda tests.gcno main.o

re: fclean all

debug: CPPFLAGS += -g3 -ggdb
debug: re

.PHONY: all clean fclean re
