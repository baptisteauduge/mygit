## Sorbonne University, 2022 - 2023
## MyGit Project
##
## Makefile
## File description:
## Makefile for MyGit project

SRC 		=  	src/main.c												\
						src/libs/list.c										\
						src/libs/hash.c										\
						src/libs/filesystem.c							\
						src/worktree.c

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

worktree.o: worktree.c
	$(CC) -c $(CFLAGS) worktree.c

fclean:
	rm $(NAME) $(OBJ)

re: fclean all

.PHONY: all fclean re $(NAME)