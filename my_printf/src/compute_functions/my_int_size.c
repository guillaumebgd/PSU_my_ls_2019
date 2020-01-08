/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_int_size.c
*/

int my_int_size(int nb, int i)
{
    if (nb == 0 && i == 0)
        return (1);
    while (nb >= 9) {
        nb /= 10;
        i += 1;
    }
    return (i);
}