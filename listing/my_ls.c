/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** single_arg.c
*/

#include "my_ls.h"
#include "my.h"
#include <stdlib.h>

static void print_total_blocks(file_list_t *tmp, file_list_t *end)
{
    long int block_size = 0;

    while (tmp != end) {
        block_size += tmp->file_stat.st_blocks;
        tmp = tmp->next;
    }
    block_size += tmp->file_stat.st_blocks;
    my_putstr(1, "total ");
    my_put_nbr(1, block_size / 2, "0123456789", 10);
    my_putchar(1, '\n');
}

static void print_stock_files(file_list_t **head, flags_t mode)
{
    file_list_t *tmp = (*head);

    if (mode.flag_l == 1)
        print_total_blocks(tmp, (*head)->prev);
    while (tmp != (*head)->prev) {
        if (mode.flag_l == 1)
            print_flag_l(tmp);
        my_putstr(1, tmp->name);
        my_putchar(1, '\n');
        tmp = tmp->next;
    }
    if (mode.flag_l == 1)
        print_flag_l(tmp);
    my_putstr(1, tmp->name);
    my_putchar(1, '\n');
}

void my_ls(file_list_t **head, flags_t mode)
{
    if ((*head) == NULL)
        return;
    if (mode.flag_t != 1)
        sort_names(head);
    if (mode.flag_lower_r == 1)
        apply_lower_r(head);
    print_stock_files(head, mode);
}