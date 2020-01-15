/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** free_list_dir.c
*/

#include "my_ls.h"
#include <stdlib.h>

void free_list_dir(list_file_list_t **head)
{
    list_file_list_t *tmp = NULL;

    if (!(*head))
        return;
    tmp = (*head);
    if (tmp->pathway)
        free(tmp->pathway);
    while (tmp) {
        (*head) = (*head)->next;
        free_file_list_t(&tmp->head);
        if (tmp)
            free(tmp);
        tmp = (*head);
    }
}