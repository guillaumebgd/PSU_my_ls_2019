/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** redirect_add_ptr.c
*/

#include "my_printf.h"
#include "my.h"

void flag_p(va_list ap, counters_t *count)
{
    my_putstr("0x", &count->printed_char);
    my_put_address((long unsigned int)va_arg(ap, void *),
                    "0123456789abcdef", 16, &count->printed_char);
}