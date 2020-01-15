/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** frees a doubly circular linked list file_list_t
*/

#include "my_ls.h"
#include <stdlib.h>

void free_file_list_t(file_list_t **head)
{
    file_list_t *save = NULL;
    file_list_t *tmp = NULL;

    if ((*head) == NULL)
        return;
    save = (*head)->prev;
    tmp = (*head);
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