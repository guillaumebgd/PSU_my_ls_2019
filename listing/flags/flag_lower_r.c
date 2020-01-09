/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** flag_lower_r.c
*/

#include "my_ls.h"
#include "my.h"
#include <stddef.h>

void apply_lower_r(file_list_t **head)
{
    file_list_t *begin = NULL;
    file_list_t *end = NULL;

    if ((*head) == NULL || (*head)->next == (*head))
        return;
    begin = (*head);
    end = (*head)->prev;
    while (begin != end && (begin->prev == end && end != (*head))) {
        my_str_swap(&begin->name, &end->name);
        swap_stats(&begin->file_stat, &end->file_stat);
        begin = begin->next;
        end = end->prev;
    }
}