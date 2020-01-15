/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** reverses the usual print
*/

#include "my_ls.h"
#include "my.h"
#include <stddef.h>

static int get_nb_nodes(file_list_t **head)
{
    file_list_t *tmp = NULL;
    int i = 1;

    if (!(*head))
        return (0);
    tmp = (*head);
    while (tmp != (*head)->prev) {
        i += 1;
        tmp = tmp->next;
    }
    return (i);
}

void apply_lower_r(file_list_t **head)
{
    file_list_t *begin = NULL;
    file_list_t *end = NULL;
    int pos = 0;
    int nb_nodes = 0;

    if (!(*head) || (*head) == (*head)->next)
        return;
    begin = (*head);
    end = (*head)->prev;
    nb_nodes = get_nb_nodes(head);
    while (pos < (nb_nodes / 2)) {
        my_str_swap(&begin->name, &end->name);
        swap_stats(&begin, &end);
        begin = begin->next;
        end = end->prev;
        pos += 1;
    }
}