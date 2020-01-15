/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** check_for_subdirectories.c
*/

#include "my_ls.h"
#include <stddef.h>

void check_for_subdirectories(file_list_t **head, flags_t mode)
{
    file_list_t *tmp = (*head);

    while (tmp != (*head)->prev) {
        if (tmp->sub_dir != NULL)
            print_ls(&tmp->sub_dir, mode);
        tmp = tmp->next;
    }
    if (tmp->sub_dir != NULL)
        print_ls(&tmp->sub_dir, mode);
}