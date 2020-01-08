/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_strncmp.c
*/

#include "my.h"

int my_strncmp(const char *to_find, const char *template)
{
    int match = 0;
    int i = 0;
    int n = my_strlen(template);

    while ((to_find[i] != '\0' && template[i] != '\0') || i < n) {
        if (to_find[i] != template[i])
            return (1);
        if (to_find[i] == template[i])
            match += 1;
        i += 1;
    }
    if (match == n)
        return (0);
    return (1);
}