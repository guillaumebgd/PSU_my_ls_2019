/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** sorts files by last time modification
*/

#include "my_ls.h"
#include "my.h"
#include <sys/stat.h>
#include <stddef.h>
#include <time.h>

static unsigned int check_if_sorted(file_list_t **head)
{
    file_list_t *tmp = (*head);

    while (tmp != (*head)->prev) {
        if (tmp->file_stat.st_mtime < tmp->next->file_stat.st_mtime)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

void sort_last_edit(file_list_t **head)
{
    file_list_t *tmp = (*head);

    if ((*head) == NULL || (*head)->prev == (*head))
        return;
    while (check_if_sorted(head) == 1) {
        while (tmp != (*head)->prev) {
            if (tmp->file_stat.st_mtime < tmp->next->file_stat.st_mtime) {
                my_str_swap(&tmp->name, &tmp->next->name);
                swap_stats(&tmp, &tmp->next);
            }
            tmp = tmp->next;
        }
        tmp = (*head);
    }
}