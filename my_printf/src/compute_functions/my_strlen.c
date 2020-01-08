/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** gets a string length if theres an error returns -1
*/

int my_strlen(char const *str)
{
    int i = -1;

    if (str == 0)
        return (-1);
    while (str[++i]);
    return (i);
}
