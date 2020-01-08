/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** single_arg.c
*/

#include "my.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>

static unsigned int get_nb_list(struct dirent *dir_stat, DIR *directory)
{
    unsigned int nb_list = 0;

    directory = opendir("./");
    dir_stat = readdir(directory);
    while (dir_stat != NULL) {
        if (dir_stat->d_name[0] != '.')
            nb_list += 1;
        dir_stat = readdir(directory);
    }
    return (nb_list);
}

static void parse_printing(struct dirent **dir_stat, unsigned int *nb_list)
{
    if ((*nb_list) == 1)
        my_printf("%s\n", (*dir_stat)->d_name);
    else
        my_printf("%s ", (*dir_stat)->d_name);
    (*nb_list) -= 1;
}

void single_arg(void)
{
    struct dirent *dir_stat = NULL;
    DIR *directory = NULL;
    unsigned int nb_list = get_nb_list(dir_stat, directory);

    directory = opendir("./");
    dir_stat = readdir(directory);
    while (dir_stat != NULL) {
        if (dir_stat->d_name[0] != '.')
            parse_printing(&dir_stat, &nb_list);
        dir_stat = readdir(directory);
    }
    closedir(directory);
}