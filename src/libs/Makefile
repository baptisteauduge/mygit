## Sorbonne University, 2022 - 2023
## MyGit Project
##
## Makefile
## File description:
## Makefile for MyGit project

SRC 		= 	cell.c 										\
					  list.c										\
						convert_list.c						\
						hash.c										\
						filesystem.c							\
						file_rights.c							\
						workfile.c 								\
						convert_workfile.c				\
						worktree.c 								\
						convert_worktree.c				\
						file_worktree.c						

OBJ 		= 	$(SRC:.c=.o)

######################################################################

CFLAGS	= 	-Wall -Wextra -Werror

CC 			=		gcc

# Main rules
all: $(OBJ)
	
cell.o: cell.c
	$(CC) -c $(CFLAGS) cell.c

list.o: list.c cell.o
	$(CC) -c $(CFLAGS) list.c

convert_list.o: convert_list.c list.o
	$(CC) -c $(CFLAGS) convert_list.c

hash.o: hash.c
	$(CC) -c $(CFLAGS) hash.c

filesystem.o: filesystem.c list.o hash.o
	$(CC) -c $(CFLAGS) filesystem.c

file_rights.o: file_rights.c filesystem.o
	$(CC) -c $(CFLAGS) file_rights.c

workfile.o: workfile.c
	$(CC) -c $(CFLAGS) workfile.c

convert_workfile.o: convert_workfile.c workfile.o
	$(CC) -c $(CFLAGS) convert_workfile.c 

worktree.o: worktree.c hash.o workfile.o
	$(CC) -c $(CFLAGS) worktree.c

convert_worktree.o: convert_worktree.c worktree.o
	$(CC) -c $(CFLAGS) convert_worktree.c

file_worktree.o: file_worktree.c worktree.o convert_worktree.o hash.o filesystem.o
	$(CC) -c $(CFLAGS) file_worktree.c

######################################################################

fclean:
	rm $(OBJ)

re: fclean all

.PHONY: all fclean re $(NAME)