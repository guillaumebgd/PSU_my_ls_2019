/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** sort_stock_files.c
*/

#include "my.h"
#include <stddef.h>

static unsigned int check_if_sorted(char ***stock_files,
                                    const unsigned int nb_list)
{
    unsigned int upper_save = 0;
    unsigned int i = 0;

    while (i < nb_list - 1) {
        if (my_is_uppercase((*stock_files)[i + 1][0]) == 0) {
            (*stock_files)[i + 1][0] += 32;
            upper_save = 1;
        }
        if ((*stock_files)[i][0] > (*stock_files)[i + 1][0])
            return (1);
        if (upper_save == 1) {
            (*stock_files)[i + 1][0] -= 32;
            upper_save = 0;
        }
        i += 1;
    }
    return (0);
}

void sort_stock_files(char ***stock_files,
                        const unsigned int nb_list)
{
    unsigned int i = 0;
    char *tmp = NULL;

    if (nb_list == 0 || nb_list == 1)
        return;
    while (check_if_sorted(stock_files, nb_list) == 1) {
        while (i < nb_list - 1) {
            if (my_strcmp((*stock_files)[i], (*stock_files)[i + 1]) > 0) {
                tmp = (*stock_files)[i];
                (*stock_files)[i] = (*stock_files)[i + 1];
                (*stock_files)[i + 1] = tmp;
            }
            i += 1;
        }
        i = 0;
    }
}