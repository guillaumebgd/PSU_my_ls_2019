/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_strcat.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char const *first, char const *second)
{
    char *res = NULL;
    int i = -1;
    int j = -1;

    if (first == NULL || second == NULL)
        return (first == NULL) ? my_strdup(second) : my_strdup(first);
    while (first[++i]);
    while (second[++j]);
    res = malloc(sizeof(char) * (i + j + 1));
    if (res == NULL)
        return (NULL);
    i = -1;
    j = -1;
    while (first[++i])
        res[++j] = first[i];
    i = -1;
    while (second[++i])
        res[++j] = second[i];
    res[++j] = '\0';
    return (res);
}
