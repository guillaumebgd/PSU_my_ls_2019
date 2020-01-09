/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_str_swap.c
*/

#include <stddef.h>

void my_str_swap(char **first, char **second)
{
    char *tmp = NULL;

    tmp = (*first);
    (*first) = (*second);
    (*second) = tmp;
}