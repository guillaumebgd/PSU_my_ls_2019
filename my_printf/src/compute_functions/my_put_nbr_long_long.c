/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** puts a nb on stdout considering its base
*/

#include "my.h"

void my_put_nbr_long_long(long long int nb,
                        char const *base,
                        long long unsigned int len_base,
                        int *printed_chars)
{
    if (nb < 0) {
        my_putchar('-');
        (*printed_chars) += 1;
        my_put_nbr(-nb, base, len_base, printed_chars);
    } if (nb >= (long long int)len_base) {
        my_put_nbr(nb / len_base, base, len_base, printed_chars);
        my_put_nbr(nb % len_base, base, len_base, printed_chars);
    } else if (nb >= 0) {
        my_putchar(base[nb]);
        (*printed_chars) += 1;
    }
}
