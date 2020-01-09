/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** single_arg.c
*/

#include "my_ls.h"
#include "my.h"
#include <stdlib.h>

static void print_stock_files(file_list_t **head)
{
    file_list_t *tmp = (*head);

    while (tmp != (*head)->prev) {
        my_putstr(1, tmp->name);
        my_putchar(1, '\n');
        tmp = tmp->next;
    }
    my_putstr(1, tmp->name);
    my_putchar(1, '\n');
}

void my_ls(file_list_t **head)
{
    if ((*head) == NULL)
        return;
    sort_names(head);
    print_stock_files(head);
}