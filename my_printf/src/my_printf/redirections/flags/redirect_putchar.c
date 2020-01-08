/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** redirect_putchar.c
*/

#include "my_printf.h"
#include "my.h"

void flag_c(va_list ap, counters_t *counter)
{
    my_putchar(va_arg(ap, int));
    counter->printed_char += 1;
}