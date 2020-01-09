/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_time.c
*/

#include "my_ls.h"
#include "my.h"
#include <time.h>

static void print_month_and_nb(char *time_info, unsigned int *i)
{
    while ((*i) < 10) {
        my_putchar(1, time_info[(*i)]);
        (*i) += 1;
    }
}

static void print_last_change(char *time_info, unsigned int *i)
{
    while ((*i) < 16) {
        my_putchar(1, time_info[(*i)]);
        (*i) += 1;
    }
}

void print_time(file_list_t *tmp)
{
    char *time_info = ctime(&(tmp->file_stat.st_mtime));
    unsigned int i = 4;

    print_month_and_nb(time_info, &i);
    print_last_change(time_info, &i);
}