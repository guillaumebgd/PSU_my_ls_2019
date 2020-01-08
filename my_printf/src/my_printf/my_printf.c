/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** similar to the stdio function
*/

#include "my_printf.h"
#include "my.h"
#include <stdlib.h>

static void init_structures(counters_t *count, arr_ptr *array_ptr)
{
    count->printed_char = 0;
    count->i = 0;
    array_ptr->list_redir = NULL;
    array_ptr->list_mod = NULL;
}

static void free_lists(path_taker **list_redir, mod_checker **list_mod)
{
    if ((*list_redir) != NULL)
        free((*list_redir));
    if ((*list_mod) != NULL)
        free((*list_mod));
}

static int browse_through_input(char const *input, va_list ap)
{
    arr_ptr array_ptr;
    counters_t count;
    int result = 0;

    init_structures(&count, &array_ptr);
    while (input[count.i]) {
        if (input[count.i] == '%') {
            result = get_flag(&input[count.i], &array_ptr, &count, ap);
            if (result == 84)
                return (-1);
            count.i += 1;
        } else {
            my_putchar(input[count.i]);
            count.printed_char += 1;
        }
        count.i += 1;
    }
    free_lists(&array_ptr.list_redir, &array_ptr.list_mod);
    return (count.printed_char);
}

int my_printf(char const *input, ...)
{
    va_list ap;
    int printed_char = 0;

    va_start(ap, input);
    printed_char = browse_through_input(input, ap);
    va_end(ap);
    return (printed_char);
}