/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** checks if a directory exists in a list to call its print
*/

#include "my_ls.h"
#include "my.h"
#include <stddef.h>

static void recursive_call(file_list_t *tmp, flags_t mode, int *no_return)
{
    if (*no_return == FALSE)
        my_putchar(1, '\n');
    else
        *no_return = FALSE;
    my_putstr(1, tmp->pathway);
    my_putstr(1, ":\n");
    print_ls(&tmp->sub_dir, mode);
}

void check_for_subdirectories(file_list_t **head, flags_t mode)
{
    file_list_t *tmp = (*head);
    static int no_return = TRUE;

    while (tmp != (*head)->prev) {
        if (tmp->sub_dir != NULL)
            recursive_call(tmp, mode, &no_return);
        tmp = tmp->next;
    }
    if (tmp->sub_dir != NULL)
        recursive_call(tmp, mode, &no_return);
}