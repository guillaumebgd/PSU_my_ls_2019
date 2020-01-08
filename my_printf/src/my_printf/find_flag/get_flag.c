/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** get_flag.c
*/

#include "my_printf.h"
#include "my.h"
#include <stddef.h>

static int initialize_arrays(arr_ptr *array_ptr)
{
    if (array_ptr->list_redir == NULL) {
        initialize_path_taker(array_ptr);
        if (array_ptr->list_redir == NULL)
            return (84);
    } if (array_ptr->list_mod == NULL) {
        initialize_modifiers(array_ptr);
        if (array_ptr->list_redir == NULL)
            return (84);
    }
    return (0);
}

static int check_behind(char const *shifted_input,
                        arr_ptr *array_ptr,
                        counters_t *count,
                        va_list ap)
{
    int call_redir = 0;

    call_redir = check_for_flag(shifted_input[1]);
    if (call_redir > -1) {
        array_ptr->list_redir[call_redir].flag_list(ap, count);
        return (0);
    }
    call_redir = check_for_mod(shifted_input[1]);
    if (call_redir > -1) {
        array_ptr->list_mod[call_redir].mod_list(shifted_input, count, ap);
        return (0);
    }
    return (1);
}

static int few_cases(char const *shifted_input,
                        int call_redir,
                        counters_t *count)
{
    if (shifted_input[1] != '\0' && call_redir == 1) {
        my_putchar('%');
        my_putchar(shifted_input[1]);
        count->printed_char += 2;
        return (0);
    } if (shifted_input[1] == '\0') {
        count->i -= 1;
        return (0);
    }
    return (1);
}

int get_flag(char const *shifted_input,
            arr_ptr *array_ptr,
            counters_t *count,
            va_list ap)
{
    int call_redir = 0;

    if (initialize_arrays(array_ptr) == 84)
        return (84);
    call_redir = check_behind(shifted_input, array_ptr, count, ap);
    if (shifted_input[1] == '%') {
        flag_percent(shifted_input, count);
        count->i += 1;
        return (0);
    }
    if (few_cases(shifted_input, call_redir, count) == 0)
        return (0);
    return (-1);
}