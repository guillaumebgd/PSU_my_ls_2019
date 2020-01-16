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

static int my_ls_errors(const int error)
{
    static const int cmp[] = {EPERM, ENOENT, EACCES};
    int i = 0;

    while (cmp[i]) {
        if (error == cmp[i])
            return (0);
        i += 1;
    }
    return (1);
}

void directory_error(const int error, const char *pathway,
                        int *index_issue)
{
    if (my_ls_errors(error) == 0) {
        my_putstr(2, "./my_ls: cannot access ");
        my_putchar(2, '\'');
        my_putstr(2, pathway);
        my_putchar(2, '\'');
        my_putstr(2, ": ");
        my_putstr(2, strerror(errno));
        my_putchar(2, '\n');
        *index_issue = 84;
    }
}