##
## EPITECH PROJECT, 2019
## Makefile my_ls
## File description:
## compiles c files with libs into my_ls program
##

SRC	=	listing/my_ls.c									\
		listing/print_listing.c							\
		listing/check_for_subdirectories.c				\
		listing/get_information/set_mode.c				\
		listing/get_information/get_mode.c				\
		listing/initializers/init_set_mode.c			\
		listing/initializers/init_modes.c				\
		listing/linked_list/fill_list_directories.c		\
		listing/linked_list/create_file_list.c			\
		listing/linked_list/directory_read_error.c		\
		listing/linked_list/free_list_dir.c				\
		listing/linked_list/free_file_list_t.c			\
		listing/flags/flag_l.c							\
		listing/flags/flag_d.c							\
		listing/flags/print_time.c						\
		listing/flags/flag_lower_r.c					\
		listing/flags/sort_names.c						\
		listing/flags/sort_last_edit.c

SRCTEST	=	tests/test_my_ls_simple.c

MAIN	=	main.c

VPATH	=	/usr/local/lib/

NAME	=	my_ls

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include/

LDFLAGS	=	-L./lib/my

LDLIBS	=	-lmy

LDLIBTEST	=	-lmy -lcriterion

all:	$(NAME)

$(NAME):
	$(MAKE) -C lib/my
	$(CC) -o $@ $(MAIN) $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

debug:
	$(MAKE) -C lib/my
	$(CC) -g -o $@ $(SRC) $(MAIN) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

tests_run:
	$(MAKE) -C lib/my
	$(CC) -o $@ $(SRC) $(SRCTEST) $(CPPFLAGS) $(LDFLAGS) $(LDLIBTEST) --coverage
	./$@
	$(RM) $@

coverage:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

clean:
	$(RM) $(NAME)
	$(RM) debug
	$(RM) tests_run

fclean:	clean
	$(RM) *.gcda *.gcno
	$(RM) vgcore.*
	$(RM) lib/my/*.a
	$(RM) lib/my/*.o

re:	fclean all

.NOTPARALLEL:
.PHONY: all debug tests_run coverage clean fclean re