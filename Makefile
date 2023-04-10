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
													src/libs/file/read_file.c													\
													src/libs/file/copy_file.c													\
													src/libs/file/create_blob.c												\
													src/libs/file/list_files.c												\
													src/libs/file/rights_file.c												\
													src/libs/file/get_path_absolute.c									\
													src/libs/hash/hash.c															\
													src/libs/work_file/work_file.c										\
													src/libs/work_file/convert_str_work_file.c				\
													src/libs/work_tree/work_tree.c										\
													src/libs/work_tree/convert_str_work_tree.c				\
													src/libs/work_tree/insert_get_search_work_tree.c	\
													src/libs/work_tree/save_get_file_work_tree.c			\
													src/libs/work_tree/create_blob_of_work_tree.c			\
													src/libs/work_tree/save_content_and_work_tree.c 	\
													src/libs/work_tree/restore_work_tree.c 						


SRC_TEST			=						tests/test.c																			\
													tests/libs/test_cell.c														\
													tests/libs/test_list.c														\

OBJ						=						$(SRC:.c=.o)

OBJ_TEST			=						$(SRC_TEST:.c=.o)

NAME					=						mygit

CC						=						gcc

CFLAGS				=						-Wall -Wextra -Werror

CPPFLAGS			=						-I./include

all: $(NAME)

$(NAME): $(OBJ) main.o
	$(CC) -o $(NAME) $(CFLAGS) $(CPPFLAGS) $(OBJ) main.o

tests_run: $(OBJ_TEST) $(OBJ)
	gcc -o unit_tests $(OBJ_TEST) $(OBJ)
	./unit_tests

tests_memory: $(OBJ_TEST) $(OBJ)
	gcc -o unit_tests $(OBJ_TEST) $(OBJ)
	leaks --atExit -- ./unit_tests

$(OBJ_TEST): %.o: %.c
	gcc -c $(CFLAGS) -I./tests $< -o $@

main.o: src/main.c
	gcc -c $(CFLAGS) $(CPPFLAGS) src/main.c

clean:
	$(RM) $(OBJ) $(OBJ_TEST) src/main.o tests/test.o

fclean: clean
	$(RM) $(NAME) unit_tests

re: fclean all

debug: CPPFLAGS += -g3 -ggdb
debug: re

.PHONY: all clean fclean re
