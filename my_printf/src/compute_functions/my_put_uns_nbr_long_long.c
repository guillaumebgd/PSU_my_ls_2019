/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** puts a nb on stdout considering its base
*/

#include "my.h"

void my_put_uns_nbr_long_long(long long unsigned int nb,
                            char const *base,
                            long long unsigned int len_base,
                            int *printed_chars)
{
    if (nb >= len_base) {
        my_put_nbr(nb / len_base, base, len_base, printed_chars);
        my_put_nbr(nb % len_base, base, len_base, printed_chars);
    } else {
        my_putchar(base[nb]);
        (*printed_chars) += 1;
    }
}
