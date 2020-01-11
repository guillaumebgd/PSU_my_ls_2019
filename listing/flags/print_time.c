/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_time.c
*/

#include "my_ls.h"
#include "my.h"
#include <time.h>

static unsigned int print_month(const char *shifted_time_info)
{
    unsigned int i = 0;

    if (shifted_time_info == NULL)
        return (0);
    while ((shifted_time_info[i] >= 65 && shifted_time_info[i] <= 90)
            || (shifted_time_info[i] >= 97 && shifted_time_info[i] <= 122)) {
        my_putchar(1, shifted_time_info[i]);
        i += 1;
    }
    return (i);
}

static unsigned int print_nb(const char *shifted_time_info,
                            unsigned int i)
{
    int nb = my_getnbr(shifted_time_info);
    int size = my_int_size(nb);

    my_putchar(1, ' ');
    my_put_nbr(1, nb, "0123456789", 10);
    i += size + 1;
    return (i);
}

static void print_hours_min(const char *shifted_time_info)
{
    unsigned int i = 0;

    my_putchar(1, ' ');
    while (i < 5) {
        my_putchar(1, shifted_time_info[i]);
        i += 1;
    }
}

void print_time(file_list_t *tmp)
{
    char *time_info = ctime(&(tmp->file_stat.st_mtime));
    unsigned int i = 0;

    //printf("\n\n%s\n\n", time_info);
    if (time_info == NULL)
        return;
    i = print_month(&time_info[4]) + 5;
    if (time_info[i] == ' ') {
        i += 1;
        i = print_nb(&time_info[i], i);
    } else
        i = print_nb(&time_info[i], i);
    print_hours_min(&time_info[i]);
}