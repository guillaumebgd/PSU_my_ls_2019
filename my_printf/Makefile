##
## EPITECH PROJECT, 2019
## Makefile my_printf
## File description:
## compiles c files into a lib
##

SRC		=	./src/compute_functions/my_put_nbr.c						\
			./src/compute_functions/my_put_nbr_long.c					\
			./src/compute_functions/my_put_nbr_long_long.c				\
			./src/compute_functions/my_put_nbr_short.c					\
			./src/compute_functions/my_put_uns_nbr_long.c				\
			./src/compute_functions/my_put_uns_nbr_long_long.c			\
			./src/compute_functions/my_put_uns_nbr.c					\
			./src/compute_functions/my_put_uns_nbr_short.c				\
			./src/compute_functions/my_put_address.c					\
			./src/compute_functions/my_putchar.c						\
			./src/compute_functions/my_putstr.c							\
			./src/compute_functions/my_strlen.c							\
			./src/compute_functions/my_strncmp.c						\
			./src/my_printf/find_flag/get_flag.c						\
			./src/my_printf/find_flag/create_flag_array.c				\
			./src/my_printf/find_flag/check_for_flag.c					\
			./src/my_printf/redirections/flags/redirect_putchar.c		\
			./src/my_printf/redirections/flags/redirect_put_nbr.c		\
			./src/my_printf/redirections/flags/redirect_lower_upper.c	\
			./src/my_printf/redirections/flags/redirect_add_ptr.c		\
			./src/my_printf/redirections/flags/redirect_percent.c		\
			./src/my_printf/redirections/modifiers/redirect_hashtag.c	\
			./src/my_printf/redirections/modifiers/redirect_long.c		\
			./src/my_printf/redirections/modifiers/redirect_short.c		\
			./src/my_printf/my_printf.c

CFLAGS	=	-Wall -Wextra -I./../include/

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

LIB		=	-L. -lmy

CRIT	=	--coverage -lcriterion

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
