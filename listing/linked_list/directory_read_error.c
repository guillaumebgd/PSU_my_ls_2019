/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** treats errors when a file couldn't be
*/

#include "my.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>

void directory_error(const int error, const char *pathway)
{
    my_putstr(2, "./my_ls: cannot access ");
    my_putchar(2, '\'');
    my_putstr(2, pathway);
    my_putchar(2, '\'');
    my_putstr(2, ": ");
    my_putstr(2, strerror(errno));
    my_putchar(2, '\n');
}