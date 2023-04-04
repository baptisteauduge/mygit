## Sorbonne University, 2022 - 2023
## MyGit Project
##
## Makefile
## File description:
## Makefile for MyGit project

SRC 		=   list.c										\
						hash.c										\
						filesystem.c

OBJ 		= 	$(SRC:.c=.o)

######################################################################

CFLAGS	= 	-Wall -Wextra -Werror

CC 			=		gcc

# Main rules
all: $(OBJ)
	
list.o: list.c
	$(CC) -c $(CFLAGS) list.c

hash.o: hash.c
	$(CC) -c $(CFLAGS) hash.c

filesystem.o: filesystem.c list.o hash.o
	$(CC) -c $(CFLAGS) filesystem.c

######################################################################

fclean:
	rm $(OBJ)

re: fclean all

.PHONY: all fclean re $(NAME)