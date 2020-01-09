##
## EPITECH PROJECT, 2019
## Makefile lib
## File description:
## makefile for lib
##

SRC	=	./my_putchar.c		\
		./my_putstr.c		\
		./my_strlen.c		\
		./my_strdup.c		\
		./my_strcmp.c		\
		./my_is_uppercase.c	\
		./my_strcat.c		\
		./my_str_swap.c		\
		./my_put_nbr.c

CFLAGS	=	-Wall -Wextra -I./../../include/

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) *.o

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
