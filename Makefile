##
## EPITECH PROJECT, 2019
## Makefile my_ls_bootstrap
## File description:
## compiles c files into a lib
##

SRC		=	./flag_handle/flag_precision.c		\
			./flag_handle/single_arg.c			\
			./flag_handle/handle_second_arg.c

MAIN	=	./main.c

CFLAGS	=	-Wall -Wextra -I./include/

NAME	=	my_ls

CRIT	=	-lcriterion --coverage

LIB		=	-L./my_printf -lmy

all:	$(NAME)

$(NAME):
	$(MAKE) -C ./my_printf
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(LIB) $(CFLAGS)

valgrind:
	$(MAKE) -C ./my_printf
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(LIB) $(CFLAGS) -g
	valgrind ./$(NAME)
	$(RM) $(NAME)

tests_run:
	$(MAKE) -C ./my_printf
	$(RM) *.gcda *.gcno
	$(CC) -o unit_tests $(SRC) tests/*.c $(LIB) $(CRIT) $(CFLAGS)
	./unit_tests
	$(RM) unit_tests
	$(RM) test_*

coverage:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

clean:
	$(RM) $(NAME)
	$(RM) *.gcda *.gcno

fclean:	clean
	$(RM) ./my_printf/*.a
	$(RM) ./my_printf/src/*.o

re:	fclean all

.PHONY: all tests_run coverage clean fclean re
