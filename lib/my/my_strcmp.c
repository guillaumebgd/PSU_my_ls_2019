/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** compares two strings
*/

#include "my.h"
#include <stdlib.h>

static unsigned int check_null(char const *to_find, char const *template)
{
    if (!to_find || !template) {
        if (!to_find && !template)
            return (0);
        if ((!to_find && template) || (to_find && !template))
            return (to_find) ? 1 : 0;
    }
    return (2);
}

static void change_uppercase(char **to_find, char **template)
{
    if (my_is_uppercase((*to_find)[0]) == 0)
        (*to_find[0]) += 32;
    if (my_is_uppercase((*template)[0]) == 0)
        (*template)[0] += 32;
}

int my_strcmp(char *to_find, char *template)
{
    char *to_find_dup = my_strdup(to_find);
    char *template_dup = my_strdup(template);
    unsigned int checker = 0;
    unsigned int match = 0;
    unsigned int i = 0;

    checker = check_null(to_find, template);
    if (checker == 1 || checker == 0)
        return (checker == 1) ? 1 : 0;
    change_uppercase(&to_find_dup, &template_dup);
    while (to_find_dup[i] != '\0' && template_dup[i] != '\0') {
        if (to_find_dup[i] != template_dup[i]) {
            return (to_find_dup[i] - template_dup[i]);
        } if (to_find_dup[i] == template_dup[i])
            match += 1;
        i += 1;
    }
    return (to_find_dup[i] - template_dup[i]);
}