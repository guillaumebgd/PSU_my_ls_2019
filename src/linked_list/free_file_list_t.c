/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** frees a doubly circular linked list file_list_t
*/

#include "my_ls.h"
#include <stdlib.h>

static void free_each_node(file_list_t **tmp)
{
    if ((*tmp)->pathway)
        free((*tmp)->pathway);
    if ((*tmp)->name)
        free((*tmp)->name);
    if ((*tmp)->sub_dir)
        free_file_list_t(&(*tmp)->sub_dir);
    if (*tmp)
        free(*tmp);
}

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
        free_each_node(&tmp);
        tmp = (*head);
    }
    free_each_node(&tmp);
}