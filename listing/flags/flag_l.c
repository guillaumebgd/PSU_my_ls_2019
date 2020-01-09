/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_flag_l.c
*/

#include "my_ls.h"
#include "my.h"
#include <sys/sysmacros.h>

static void print_file_type(file_list_t *tmp)
{
    if (S_ISDIR(tmp->file_stat.st_mode)) {
        my_putchar(1, 'd');
        return;
    } if (S_ISCHR(tmp->file_stat.st_mode)) {
        my_putchar(1, 'c');
        return;
    } if (S_ISLNK(tmp->file_stat.st_mode)) {
        my_putchar(1, 'l');
        return;
    } if (S_ISBLK(tmp->file_stat.st_mode)) {
        my_putchar(1, 'b');
        return;
    } if (S_ISFIFO(tmp->file_stat.st_mode)) {
        my_putchar(1, 'p');
        return;
    } if (S_ISSOCK(tmp->file_stat.st_mode)) {
        my_putchar(1, 's');
        return;
    }
    my_putchar(1, '-');
}

static void print_first_column(file_list_t *tmp)
{
    my_putchar(1, (tmp->file_stat.st_mode & S_IRUSR) ? 'r' : '-');
    my_putchar(1, (tmp->file_stat.st_mode & S_IWUSR) ? 'w' : '-');
    my_putchar(1, (tmp->file_stat.st_mode & S_IXUSR) ? 'x' : '-');
    my_putchar(1, (tmp->file_stat.st_mode & S_IRGRP) ? 'r' : '-');
    my_putchar(1, (tmp->file_stat.st_mode & S_IWGRP) ? 'w' : '-');
    my_putchar(1, (tmp->file_stat.st_mode & S_IXGRP) ? 'x' : '-');
    my_putchar(1, (tmp->file_stat.st_mode & S_IROTH) ? 'r' : '-');
    my_putchar(1, (tmp->file_stat.st_mode & S_IWOTH) ? 'w' : '-');
    my_putchar(1, (tmp->file_stat.st_mode & S_IXOTH) ? 'x' : '-');
}

void print_flag_l(file_list_t *tmp)
{
    print_file_type(tmp);
    print_first_column(tmp);
    my_putchar(1, ' ');
}