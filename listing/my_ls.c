/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** similar to the ls function with -l, -r, -R and -t flags
*/

#include "my_ls.h"
#include "my.h"
#include <stddef.h>

static int is_sub_dir(file_list_t **head, flags_t mode)
{
    file_list_t *tmp = (*head);

    if (mode.flag_upper_r == FALSE)
        return (1);
    while (tmp != (*head)->prev) {
        if (tmp->sub_dir)
            return (0);
        tmp = tmp->next;
    }
    if (tmp->sub_dir)
        return (0);
    return (1);
}

static void print_every_directory(list_file_list_t **list_directories,
                                flags_t mode)
{
    list_file_list_t *tmp = (*list_directories);
    boolean sort_recurse = FALSE;

    if ((*list_directories)->next || mode.flag_upper_r == TRUE
        || is_sub_dir(&(*list_directories)->head, mode) == 0)
        sort_recurse = TRUE;
    while (tmp) {
        if (sort_recurse == TRUE) {
            if (tmp != (*list_directories))
                my_putchar(1, '\n');
            my_putstr(1, tmp->pathway);
            my_putstr(1, ":\n");
        }
        if (!(*list_directories)->next && is_sub_dir(&tmp->head, mode) == 1)
            sort_recurse = FALSE;
        print_ls(&tmp->head, mode, &sort_recurse);
        tmp = tmp->next;
    }
}

int my_ls(const int ac, const char * const *av)
{
    list_file_list_t *list_directories = NULL;
    flags_t mode;
    int index_issue = 0;

    if (fill_mode(&mode, ac, av) == 84)
        return (84);
    fill_list_directories(&list_directories, ac - 1, &av[1], &index_issue);
    if (!list_directories)
        return (84);
    print_every_directory(&list_directories, mode);
    free_list_dir(&list_directories);
    return (index_issue);
}