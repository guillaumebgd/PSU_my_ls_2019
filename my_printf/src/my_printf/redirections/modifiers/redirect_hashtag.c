/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** redirect_zero.c
*/

#include "my_printf.h"
#include "my.h"

static void normal_print(int base, counters_t *count, va_list ap)
{
    if (base == 0 || base == 1)
        flag_d(ap, count);
    else if (base == 2)
        flag_u(ap, count);
    else
        flag_b(ap, count);
}

static void modified(int base, counters_t *count, va_list ap)
{
    int octal_save = 0;

    if (base == 4) {
        octal_save = va_arg(ap, int);
        if (octal_save > 0) {
            my_putchar('0');
            count->printed_char += 1;
        }
        my_put_nbr(octal_save, "01234567", 8, &count->printed_char);
    } else if (base == 5) {
        my_putstr("0x", &count->printed_char);
        flag_lower_x(ap, count);
    } else {
        my_putstr("0x", &count->printed_char);
        flag_upper_x(ap, count);
    }
}

void mod_hashtag(char const *shifted_input, counters_t *count, va_list ap)
{
    int base = 0;

    base = check_base(shifted_input[2]);
    if (base == -1)
        return;
    if (base < 4) {
        normal_print(base, count, ap);
        count->i += 1;
    } else {
        modified(base, count, ap);
        count->i += 1;
    }
}