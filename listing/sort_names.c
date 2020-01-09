/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** sort_stock_files.c
*/

#include "my_ls.h"
#include "my.h"
#include <sys/stat.h>
#include <stddef.h>

void swap_stats(struct stat *first, struct stat *second)
{
    struct stat tmp;

    tmp = (*first);
    (*first) = (*second);
    (*second) = tmp;
}

void swap_grp(struct group **first, struct group **second)
{
    struct group *tmp;

    tmp = (*first);
    (*first) = (*second);
    (*second) = tmp;
}

void swap_pwd(struct passwd **first, struct passwd **second)
{
    struct passwd *tmp;

    tmp = (*first);
    (*first) = (*second);
    (*second) = tmp;
}

static unsigned int check_if_sorted(file_list_t **head)
{
    file_list_t *tmp = (*head);
    unsigned int upper_save = 0;

    while (tmp != (*head)->prev) {
        if (my_is_uppercase(tmp->next->name[0]) == 0) {
            tmp->next->name[0] += 32;
            upper_save = 1;
        }
        if (tmp->name[0] > tmp->next->name[0])
            return (1);
        if (upper_save == 1) {
            tmp->next->name[0] -= 32;
            upper_save = 0;
        }
        tmp = tmp->next;
    }
    return (0);
}

void sort_names(file_list_t **head)
{
    file_list_t *tmp = (*head);

    if ((*head) == NULL || (*head)->prev == (*head))
        return;
    while (check_if_sorted(head) == 1) {
        while (tmp != (*head)->prev) {
            if (my_strcmp(tmp->name, tmp->next->name) > 0) {
                my_str_swap(&tmp->name, &tmp->next->name);
                swap_stats(&tmp->file_stat, &tmp->next->file_stat);
                swap_grp(&tmp->grp_info, &tmp->grp_info);
                swap_pwd(&tmp->pwd, &tmp->pwd);
            }
            tmp = tmp->next;
        }
        tmp = (*head);
    }
}