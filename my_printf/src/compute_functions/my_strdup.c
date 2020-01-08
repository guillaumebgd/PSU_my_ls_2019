/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** duplicates a const str into a str
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest = NULL;
    int len_src = my_strlen(src);
    int i = -1;

    if (len_src == -1)
        return (NULL);
    dest = malloc(sizeof(char) * len_src + 1);
    if (dest == NULL)
        return (NULL);
    while (src[++i])
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
