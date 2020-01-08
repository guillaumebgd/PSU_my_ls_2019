/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** redirect_add_ptr.c
*/

#include "my_printf.h"
#include "my.h"

void flag_percent(char const *shifted_input, counters_t *count)
{
    int count_percent = 0;
    int i = 1;

    while (shifted_input[i] != '\0') {
        if (shifted_input[i] == '%') {
            count_percent += 1;
            if (count_percent == 2)
                break;
        }
        my_putchar(shifted_input[i]);
        count->i += 1;
        count->printed_char += 1;
        i += 1;
    }
    count->i -= 2;
}