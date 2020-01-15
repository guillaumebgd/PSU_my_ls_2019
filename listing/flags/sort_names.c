/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** sorts name by ascii order treating uppercases as lowercases
*/

#include "my_ls.h"
#include "my.h"
#include <sys/stat.h>
#include <stddef.h>

void swap_stats(file_list_t **first, file_list_t **second)
{
    struct stat tmp_stat;
    gid_t tmp_grp;
    uid_t tmp_pwd;

    tmp_stat = (*first)->file_stat;
    (*first)->file_stat = (*second)->file_stat;
    (*second)->file_stat = tmp_stat;
    tmp_grp = (*first)->grp_info;
    (*first)->grp_info = (*second)->grp_info;
    (*second)->grp_info = tmp_grp;
    tmp_pwd = (*first)->pwd;
    (*first)->pwd = (*second)->pwd;
    (*second)->pwd = tmp_pwd;
}

static int check_if_sorted(file_list_t **head)
{
    file_list_t *tmp = (*head);
    int upper_save = 0;

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
                swap_stats(&tmp, &tmp->next);
            }
            tmp = tmp->next;
        }
        tmp = (*head);
    }
}