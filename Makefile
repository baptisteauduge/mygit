## Sorbonne University, 2022 - 2023
## MyGit Project
##
## Makefile
## File description:
## Makefile for MyGit project

SRC 		=  	src/main.c												\
						src/libs/cell.c 									\
						src/libs/list.c										\
						src/libs/convert_list.c						\
						src/libs/hash.c										\
						src/libs/filesystem.c							\
						src/libs/file_rights.c						\
						src/libs/workfile.c 							\
						src/libs/convert_workfile.c				\
						src/libs/worktree.c 							\
						src/libs/convert_worktree.c				\
						src/libs/file_worktree.c								

OBJ 		= 	$(SRC:.c=.o)

######################################################################

NAME 		=		mygit

CFLAGS	= 	-Wall -Wextra -Werror -g

CC 			=		gcc

# Main rules
all:
	+$(MAKE) -C src/libs
	+$(MAKE) $(NAME)
	
$(NAME): $(OBJ)
	$(CC) -o mygit $(CFLAGS) $(OBJ)

######################################################################

main.o: main.c
	$(CC) -c $(CFLAGS) main.c

fclean:
	rm $(NAME) $(OBJ)

re: fclean all

.PHONY: all fclean re $(NAME)