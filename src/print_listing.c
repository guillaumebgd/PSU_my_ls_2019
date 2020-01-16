/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** prints a directory
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

static void print_symb_link(file_list_t *tmp, flags_t mode)
{
    if (tmp->symlink_ptr_name && mode.flag_l == TRUE) {
        my_putstr(1, " -> ");
        my_putstr(1, tmp->symlink_ptr_name);
        if (tmp->symlink_ptr_name)
            free(tmp->symlink_ptr_name);
    }
}

static void print_stock_files(file_list_t **head, flags_t mode)
{
    file_list_t *tmp = (*head);

    if (mode.flag_l == TRUE && mode.flag_d == FALSE)
        print_total_blocks(tmp, (*head)->prev);
    while (tmp != (*head)->prev) {
        if (mode.flag_l == TRUE)
            print_flag_l(tmp);
        my_putstr(1, tmp->name);
        print_symb_link(tmp, mode);
        my_putchar(1, '\n');
        tmp = tmp->next;
    }
    if (mode.flag_l == TRUE)
        print_flag_l(tmp);
    my_putstr(1, tmp->name);
    print_symb_link(tmp, mode);
    my_putchar(1, '\n');
}

void print_ls(file_list_t **head, flags_t mode, boolean *sort_recursive)
{
    if (!(*head))
        return;
    if (mode.flag_t != TRUE)
        sort_names(head);
    else
        sort_last_edit(head);
    if (mode.flag_lower_r == TRUE)
        apply_lower_r(head);
    print_stock_files(head, mode);
    if (mode.flag_upper_r == TRUE) {
        if (*sort_recursive == TRUE) {
            my_putchar(1, '\n');
            *sort_recursive = FALSE;
        }
        check_for_subdirectories(head, mode);
    }
}