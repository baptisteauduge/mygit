## Sorbonne University, 2022 - 2023
## MyGit Project
##
## Makefile
## File description:
## Makefile for tests of MyGit project

SRC 		= 	test_cell.c				\
						test_list.c				\
						test_hash.c				

OBJ 		= 	$(SRC:.c=.o)

######################################################################

CFLAGS	= 	-Wall -Wextra -Werror -g

CC 			=		gcc

# Main rules
all: $(OBJ)

test_cell.o: test_cell.c
	$(CC) $(CFLAGS) -c test_cell.c

test_list.o: test_list.c
	$(CC) $(CFLAGS) -c test_list.c

test_hash.o: test_hash.c
	$(CC) $(CFLAGS) -c test_hash.c

######################################################################

fclean:
	rm $(OBJ)

re: fclean all

.PHONY: all fclean re $(NAME)