/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** redirect_short.c
*/

#include "my_printf.h"
#include "my.h"
#include <stdlib.h>

static void short_redir(int i, counters_t *count, va_list ap)
{
    if (i == 0 || i == 1) {
        my_put_nbr_short(va_arg(ap, int), "0123456789",
                        10, &count->printed_char);
        count->i += 1;
    } if (i == 2) {
        my_put_uns_nbr_short(va_arg(ap, unsigned int), "0123456789",
                            10, &count->printed_char);
        count->i += 1;
    } if (i == 3 || i == 4) {
        my_put_nbr(va_arg(ap, int), "0123456789",
                    10, &count->printed_char);
        count->i += 2;
    } if (i == 5) {
        my_put_nbr(va_arg(ap, int), "0123456789",
                    10, &count->printed_char);
        count->i += 2;
    }
}

void mod_short(char const *shifted_input, counters_t *count, va_list ap)
{
    const char *cmp[] = {"hd", "hi", "hu", "hhd", "hhi", "hhu"};
    int i = 0;

    while (cmp[i] != NULL) {
        if (my_strncmp(&shifted_input[1], cmp[i]) == 0)
            break;
        i += 1;
    }
    short_redir(i, count, ap);
}