/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_is_uppercase.c
*/

int my_is_uppercase(const char c)
{
    if (c >= 'A' && c <= 'Z')
        return (0);
    return (1);
}