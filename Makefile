##
## EPITECH PROJECT, 2019
## Makefile my_ls_bootstrap
## File description:
## compiles c files into a lib
##

SRC		=	./listing/my_ls.c								\
			./listing/sort_names.c							\
			./listing/get_information/set_mode.c			\
			./listing/get_information/get_info.c			\
			./listing/get_information/get_mode.c			\
			./listing/initializers/init_set_mode.c			\
			./listing/initializers/init_modes.c				\
			./listing/linked_list/create_file_list.c		\
			./listing/linked_list/free_list.c				\
			./listing/linked_list/directory_read_error.c	\
			./listing/flags/flag_l.c						\
			./listing/flags/flag_lower_r.c

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
	$(RM) vgcore.*

fclean:	clean
	$(RM) lib/my/*.a
	$(RM) lib/my/*.o

re:	fclean all

.PHONY: all debug valgrind tests_run coverage clean fclean re