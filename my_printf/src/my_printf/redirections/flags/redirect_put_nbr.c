/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** redirect_put_nbr.c
*/

#include "my_printf.h"
#include "my.h"

void flag_d(va_list ap, counters_t *counter)
{
    my_put_nbr(va_arg(ap, int), "0123456789", 10, &counter->printed_char);
}

void flag_i(va_list ap, counters_t *counter)
{
    my_put_nbr(va_arg(ap, int), "0123456789", 10, &counter->printed_char);
}

void flag_u(va_list ap, counters_t *counter)
{
    my_put_uns_nbr(va_arg(ap, unsigned int), "0123456789",
                    10, &counter->printed_char);
}

void flag_b(va_list ap, counters_t *counter)
{
    my_put_nbr(va_arg(ap, int), "01", 2, &counter->printed_char);
}

void flag_o(va_list ap, counters_t *counter)
{
    my_put_nbr(va_arg(ap, int), "01234567", 8, &counter->printed_char);
}