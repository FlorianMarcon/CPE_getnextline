##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	main.c		\
		my_putstr.c	\
		my_putchar.c	\
		get_next_line.c		\
		my_strcat.c		\
		my_strlen.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	exec

CFLAGS	=	-Wall -W -Wextra -Werror -I. -g3

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	make clean -C./tests
	rm -f $(OBJ)

fclean:	clean
	make fclean -C./tests
	rm -f $(NAME)

re:	clean all

tests_run:
	make -C./tests
