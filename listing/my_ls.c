/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** similar to the ls function with -l, -r, -R and -t flags
*/

#include "my_ls.h"
#include "my.h"
#include <stdlib.h>

static void print_every_directory(list_file_list_t **list_directories,
                                    flags_t mode)
{
    list_file_list_t *tmp = (*list_directories);
    int several_dir_calls = 0;

    if (tmp->next)
        several_dir_calls = 1;
    while (tmp) {
        if (several_dir_calls == 1) {
            if (tmp != (*list_directories))
                my_putchar(1, '\n');
            my_putstr(1, tmp->pathway);
            my_putstr(1, ":\n");
        }
        print_ls(&tmp->head, mode);
        tmp = tmp->next;
    }
}

int my_ls(int ac, char **av)
{
    list_file_list_t *list_directories = NULL;
    flags_t mode;

    if (fill_mode(ac, av, &mode) == 84)
        return (84);
    fill_list_directories(ac - 1, &av[1], &list_directories);
    print_every_directory(&list_directories, mode);
    return (0);
}