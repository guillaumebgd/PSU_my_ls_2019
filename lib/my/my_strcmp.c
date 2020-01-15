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

static void set_saves(char *save_to_find, char *save_template,
                        const char c1, const char c2)
{
    (*save_to_find) = c1;
    (*save_template) = c2;
}

int compare_strings(char *to_find_dup, char *template_dup)
{
    char save_first;
    char save_second;
    unsigned int i = 0;

    while (to_find_dup[i] != '\0' && template_dup[i] != '\0') {
        set_saves(&save_first, &save_second, to_find_dup[i], template_dup[i]);
        if (save_first != save_second)
            return (save_first - save_second);
        i += 1;
    }
    set_saves(&save_first, &save_second, to_find_dup[i], template_dup[i]);
    return (save_first - save_second);
}

int my_strcmp(const char *to_find, const char *template)
{
    char *to_find_dup = my_strdup(to_find);
    char *template_dup = my_strdup(template);
    unsigned int checker = 0;
    int result = 0;

    checker = check_null(to_find, template);
    if (checker == 1 || checker == 0)
        return (checker == 1) ? 1 : 0;
    change_uppercase(&to_find_dup, &template_dup);
    result = compare_strings(to_find_dup, template_dup);
    free(to_find_dup);
    free(template_dup);
    return (result);
}