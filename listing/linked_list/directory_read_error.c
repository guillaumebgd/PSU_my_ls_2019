/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** directory_read_error.c
*/

#include "my.h"
#include <errno.h>
#include <unistd.h>

void directory_error(int error, const char *pathway)
{
    if (error == ENOENT) {
        my_putstr(2, "./my_ls: cannot access ");
        my_putchar(2, '\'');
        my_putstr(2, pathway);
        my_putchar(2, '\'');
        my_putstr(2, ": No such file or directory\n");
    }
}

/*    EACCES
    EBADF
    EMFILE
    ENOENT
    ENOMEM
    ENOTDIR*/