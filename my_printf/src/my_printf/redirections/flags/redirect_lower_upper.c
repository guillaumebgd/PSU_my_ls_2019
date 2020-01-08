/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** redirect_put_nbr.c
*/

#include "my_printf.h"
#include "my.h"

void flag_lower_x(va_list ap, counters_t *count)
{
    my_put_nbr(va_arg(ap, int), "0123456789abcdef", 16, &count->printed_char);
}

void flag_upper_x(va_list ap, counters_t *count)
{
    my_put_nbr(va_arg(ap, int), "0123456789ABCDEF", 16, &count->printed_char);
}

void flag_lower_s(va_list ap, counters_t *count)
{
    my_putstr(va_arg(ap, char *), &count->printed_char);
}

static void print_zeros(int nb)
{
    int count = 100;

    while (nb < count) {
        count /= 10;
        my_putchar('0');
    }
}

void flag_upper_s(va_list ap, counters_t *count)
{
    char const *arg = va_arg(ap, char const *);
    int i = 0;

    while (arg[i] != '\0') {
        if (arg[i] >= 32 && arg[i] <= 126) {
            my_putchar(arg[i]);
            count->printed_char += 1;
        } else {
            my_putchar('\\');
            print_zeros((int)arg[i]);
            my_put_nbr((int)arg[i], "01234567", 8, &count->printed_char);
        }
        i += 1;
    }
}