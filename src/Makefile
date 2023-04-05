## Sorbonne University, 2022 - 2023
## MyGit Project
##
## Makefile
## File description:
## Makefile for MyGit project

SRC 		=  	main.c			

OBJ 		= 	$(SRC:.c=.o)

######################################################################

CFLAGS	= 	-Wall -Wextra -Werror -g

CC 			=		gcc

# Main rules
all:
	+$(MAKE) -C libs all
	+$(MAKE) $(OBJ)
	
######################################################################

main.o: main.c
	$(CC) -c $(CFLAGS) main.c

fclean:
	+$(MAKE) -C libs fclean
	rm $(OBJ)

re: fclean all

.PHONY: all fclean re $(NAME)