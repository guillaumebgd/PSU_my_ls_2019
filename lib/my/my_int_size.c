/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_int_size.c
*/

int my_int_size(int nb)
{
    int i = 1;

    while (nb >= 10) {
        nb /= 10;
        i += 1;
    }
    return (i);
}