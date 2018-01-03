##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

WAY	=	..

SRC	=	$(WAY)/my_putstr.c	\
		$(WAY)/my_putchar.c	\
		$(WAY)/get_next_line.c		\
		$(WAY)/my_strcat.c		\
		$(WAY)/my_strlen.c		\

SRC_UT	=	is_end_line/tests_utils.c	\
		copy_extra_char/tests_utils.c	\
		get_next_line/tests_utils.c	\

OBJ	=	$(SRC:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

NAME	=	units

CFLAGS	=	-Wall -W -Wextra -Werror -I../ -g3

LDFLAGS	=	-lcriterion -lgcov --coverage

all:	$(OBJ) $(OBJ_UT)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_UT) $(LDFLAGS)
	./$(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_UT)

fclean:	clean
	rm -f $(NAME)

re:	clean all
