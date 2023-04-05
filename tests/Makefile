## Sorbonne University, 2022 - 2023
## MyGit Project
##
## Makefile
## File description:
## Makefile for MyGit project

SRC 		=  	libs/test_cell.c 									\
						../src/libs/cell.c 								\
						libs/test_list.c 									\
						../src/libs/list.c 								\
						libs/test_hash.c 									\
						../src/libs/hash.c 								\
							

OBJ 		= 	$(SRC:.c=.o)

######################################################################

NAME 		=		mygit_test

CFLAGS	= 	-Wall -Wextra -Werror -g

CC 			=		gcc

leaks:
	+$(MAKE) -C libs
	+$(MAKE) $(NAME)
	leaks --atExit -- ./$(NAME)

test:
	+$(MAKE) -C libs
	+$(MAKE) $(NAME)
	
$(NAME): $(OBJ) main_test.o
	$(CC) -o $(NAME) $(CFLAGS) main_test.o $(OBJ)

######################################################################

main_test.o: main_test.c
	$(CC) -c $(CFLAGS) main_test.c

fclean:
	+$(MAKE) -C libs fclean
	rm $(NAME) main_test.o

re: fclean all

.PHONY: all fclean re $(NAME)