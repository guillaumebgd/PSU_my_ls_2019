##
## EPITECH PROJECT, 2019
## Makefile my_ls
## File description:
## compiles c files with libs into my_ls program
##

SRC	=	listing/my_ls.c								\
		listing/sort_names.c						\
		listing/sort_last_edit.c					\
		listing/get_information/set_mode.c			\
		listing/get_information/get_info.c			\
		listing/get_information/get_mode.c			\
		listing/initializers/init_set_mode.c		\
		listing/initializers/init_modes.c			\
		listing/linked_list/create_file_list.c		\
		listing/linked_list/free_list.c				\
		listing/linked_list/directory_read_error.c	\
		listing/flags/flag_l.c						\
		listing/flags/print_time.c					\
		listing/flags/flag_lower_r.c

MAIN	=	main.c

VPATH	=	/usr/local/lib/

NAME	=	my_ls

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include/

LDFLAGS	=	-L./lib/my

LDLIBS	=	-lmy

LDLIBTEST	=	-lmy -lcriterion

all:	$(NAME)

$(NAME):	$(LDLIBTEST)
	$(CC) -o $@ $(MAIN) $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

-lmy:
	$(MAKE) -C lib/my

debug: $(LDLIBTEST)
	$(CC) -g -o $@ $(SRC) $(MAIN) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

tests_run: $(LDLIBTEST)
	$(CC) -o $@ $(SRC) tests/*.c $(CPPFLAGS) $(LDFLAGS) $(LDLIBTEST) --coverage
	./$@
	$(RM) $@

coverage:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

clean:
	$(RM) $(NAME)
	$(RM) debug
	$(RM) tests_run
	$(RM) *.gcda *.gcno
	$(RM) vgcore.*

fclean:	clean
	$(RM) lib/my/*.a
	$(RM) lib/my/*.o

re:	fclean all

.NOTPARALLEL:
.PHONY: all debug tests_run coverage clean fclean re