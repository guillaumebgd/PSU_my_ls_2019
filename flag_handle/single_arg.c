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
#include <stdlib.h>

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

static void get_files(struct dirent **dir_stat, char ***stock_files, DIR **directory)
{
    unsigned int i = 0;

    (*directory) = opendir("./");
    (*dir_stat) = readdir((*directory));
    while ((*dir_stat) != NULL) {
        if ((*dir_stat)->d_name[0] != '.') {
            (*stock_files)[i] = my_strdup((*dir_stat)->d_name);
            i += 1;
        }
        (*dir_stat) = readdir((*directory));
    }
    closedir((*directory));
}

static void print_stock_files(char **print_stock_files,
                                const unsigned int nb_list)
{
    unsigned int i = 0;

    if (nb_list == 0)
        return;
    while (i < nb_list) {
        my_putstr(print_stock_files[i]);
        if (i == nb_list - 1)
            my_putchar('\n');
        else
            my_putchar(' ');
        i += 1;
    }
}

void single_arg(void)
{
    char **stock_files = NULL;
    struct dirent *dir_stat = NULL;
    DIR *directory = NULL;
    unsigned int nb_list = 0;

    nb_list = get_nb_list(dir_stat, directory);
    stock_files = malloc(sizeof(char *) * nb_list);
    if (stock_files == NULL)
        return;
    get_files(&dir_stat, &stock_files, &directory);
    print_stock_files(stock_files, nb_list);
}