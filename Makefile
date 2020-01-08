##
## EPITECH PROJECT, 2019
## Makefile my_ls_bootstrap
## File description:
## compiles c files into a lib
##

SRC		=	./flag_handle/flag_precision.c		\
			./flag_handle/single_arg.c			\
			./flag_handle/sort_stock_files.c	\
			./flag_handle/handle_second_arg.c

MAIN	=	./main.c

CFLAGS	=	-Wall -Wextra -I./include/

NAME	=	my_ls

CRIT	=	-lcriterion --coverage

LIB		=	-L./lib/my -lmy

all:	$(NAME)

$(NAME):
	$(MAKE) -C ./lib/my
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(LIB) $(CFLAGS)

debug:
	$(MAKE) -C ./lib/my
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(LIB) $(CFLAGS) -g
	gdb ./$(NAME)
	$(RM) $(NAME)

valgrind:
	$(MAKE) -C ./lib/my
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(LIB) $(CFLAGS) -g
	valgrind --leak-check=full ./$(NAME)
	$(RM) $(NAME)

tests_run:
	$(MAKE) -C ./lib/my
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
	$(RM) lib/my/*.a
	$(RM) lib/my/*.o

re:	fclean all

.PHONY: all debug valgrind tests_run coverage clean fclean re