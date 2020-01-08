/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** put chars from a str
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str, int *printed_chars)
{
    int size = my_strlen(str);

    if (size == -1)
        return (84);
    if (write(1, str, size) < 0)
        return (84);
    (*printed_chars) += size;
    return (0);
}
