/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** prints detailled information of files
*/

#include "my_ls.h"
#include "my.h"
#include <sys/sysmacros.h>
#include <time.h>

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
    }
    my_putchar(1, '-');
}

static void print_first_column(file_list_t *tmp)
{
    print_file_type(tmp);
    my_putchar(1, (tmp->file_stat.st_mode & S_IRUSR) ? 'r' : '-');
    my_putchar(1, (tmp->file_stat.st_mode & S_IWUSR) ? 'w' : '-');
    if (tmp->file_stat.st_mode & S_ISUID)
        my_putchar(1, (tmp->file_stat.st_mode & S_IXUSR) ? 's' : 'S');
    else
        my_putchar(1, (tmp->file_stat.st_mode & S_IXUSR) ? 'x' : '-');
    my_putchar(1, (tmp->file_stat.st_mode & S_IRGRP) ? 'r' : '-');
    my_putchar(1, (tmp->file_stat.st_mode & S_IWGRP) ? 'w' : '-');
    if (tmp->file_stat.st_mode & S_ISGID)
        my_putchar(1, (tmp->file_stat.st_mode & S_IXGRP) ? 's' : 'S');
    else
        my_putchar(1, (tmp->file_stat.st_mode & S_IXGRP) ? 'x' : '-');
    my_putchar(1, (tmp->file_stat.st_mode & S_IROTH) ? 'r' : '-');
    my_putchar(1, (tmp->file_stat.st_mode & S_IWOTH) ? 'w' : '-');
    if (tmp->file_stat.st_mode & __S_ISVTX)
        my_putchar(1, (tmp->file_stat.st_mode & S_IXOTH) ? 't' : 'T');
    else
        my_putchar(1, (tmp->file_stat.st_mode & S_IXOTH) ? 'x' : '-');
    my_putchar(1, ' ');
}

void print_flag_l(file_list_t *tmp)
{
    print_first_column(tmp);
    my_put_nbr(1, tmp->file_stat.st_nlink, "0123456789", 10);
    my_putchar(1, ' ');
    my_putstr(1, getpwuid(tmp->pwd)->pw_name);
    my_putchar(1, ' ');
    my_putstr(1, getgrgid(tmp->grp_info)->gr_name);
    my_putchar(1, ' ');
    if (S_ISCHR(tmp->file_stat.st_mode) || S_ISBLK(tmp->file_stat.st_mode)) {
        my_put_nbr(1, major(tmp->file_stat.st_rdev), "0123456789", 10);
        my_putstr(1, ", ");
        my_put_nbr(1, minor(tmp->file_stat.st_rdev), "0123456789", 10);
    } else
        my_put_nbr(1, tmp->file_stat.st_size, "0123456789", 10);
    my_putchar(1, ' ');
    print_time(tmp);
    my_putchar(1, ' ');
}