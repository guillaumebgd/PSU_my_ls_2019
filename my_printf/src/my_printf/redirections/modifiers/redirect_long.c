/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** redirect_plus.c
*/

#include "my_printf.h"
#include "my.h"
#include <stdlib.h>

static void long_long_arg(int i, counters_t *count)
{
    if (i == 2 || i == 3 || i == 7)
        count->i += 1;
}

static void long_redir(int i, counters_t *count, va_list ap)
{
    if (i == 0 || i == 1) {
        my_put_nbr_long(va_arg(ap, long int), "0123456789",
                        10, &count->printed_char);
        count->i += 1;
    } if (i >= 2 && i <= 5) {
        my_put_nbr_long_long(va_arg(ap, long long int), "0123456789",
                            10, &count->printed_char);
        count->i += 1;
        long_long_arg(i, count);
    } if (i == 6) {
        my_put_uns_nbr_long(va_arg(ap, long unsigned int), "0123456789",
                            10, &count->printed_char);
        count->i += 1;
    } if (i == 7 || i == 8) {
        my_put_uns_nbr_long_long(va_arg(ap, long long unsigned int),
                                "0123456789", 10, &count->printed_char);
        count->i += 1;
        long_long_arg(i, count);
    }
}

void mod_long(char const *shifted_input, counters_t *count, va_list ap)
{
    const char *cmp[] = {"ld", "li", "lld", "lli",
                        "qd", "qi", "lu", "llu", "qu"};
    int i = 0;

    while (cmp[i] != NULL) {
        if (my_strncmp(&shifted_input[1], cmp[i]) == 0)
            break;
        i += 1;
    }
    long_redir(i, count, ap);
}