/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** free_list.c
*/

#include "my_ls.h"
#include <stdlib.h>

void free_list(file_list_t **head)
{
    file_list_t *save = (*head)->prev;
    file_list_t *tmp = (*head);

    while (tmp != save) {
        (*head) = (*head)->next;
        if (tmp->name != NULL)
            free(tmp->name);
        if (tmp != NULL)
            free(tmp);
        tmp = (*head);
    }
    if (tmp->name != NULL)
        free(tmp->name);
    if (tmp != NULL)
        free(tmp);
}