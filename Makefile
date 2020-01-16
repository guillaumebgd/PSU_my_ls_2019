##
## EPITECH PROJECT, 2019
## Makefile my_ls
## File description:
## compiles c files with libs into my_ls program
##

SRC	=	src/my_ls.c									\
		src/print_listing.c							\
		src/check_for_subdirectories.c				\
		src/get_information/set_mode.c				\
		src/get_information/get_mode.c				\
		src/initializers/init_set_mode.c			\
		src/initializers/init_modes.c				\
		src/linked_list/fill_list_directories.c		\
		src/linked_list/create_file_list.c			\
		src/linked_list/directory_read_error.c		\
		src/linked_list/free_list_dir.c				\
		src/linked_list/free_file_list_t.c			\
		src/flags/flag_l.c							\
		src/flags/flag_d.c							\
		src/flags/fill_node_info.c					\
		src/flags/print_time.c						\
		src/flags/flag_lower_r.c					\
		src/flags/sort_names.c						\
		src/flags/sort_last_edit.c

SRCTEST	=	tests/test_my_ls_simple.c				\
			tests/test_my_ls_error.c

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