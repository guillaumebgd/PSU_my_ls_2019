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
        my_putstr(tmp->name);
        my_putchar('\n');
        tmp = tmp->next;
    }
}

void my_ls(file_list_t **head)
{
    if ((*head) == NULL)
        return;
    sort_names(head);
    print_stock_files(head);
}