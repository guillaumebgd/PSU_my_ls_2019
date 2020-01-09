/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** get_mode.c
*/

#include "my_ls.h"
#include "my.h"

static void get_mode(char *argument,
                    flags_t *mode,
                    mode_fcter_arr_t *assert_flag)
{
    const char flags[] = "lRdrt";
    int len_argument = my_strlen(argument);
    unsigned int cmp = 0;
    unsigned int i = 1;

    if (len_argument <= 0)
        return;
    while (i < (unsigned int)len_argument) {
        while (flags[cmp] != '\0') {
            if (argument[i] == flags[cmp])
                assert_flag[cmp].fct_arr(mode);
            cmp += 1;
        }
        cmp = 0;
        i += 1;
    }
}

void fill_mode(int ac, char **av,
                flags_t *mode, mode_fcter_arr_t *assert_flag)
{
    unsigned int i = 0;

    init_mode(mode);
    while (i < (unsigned int)ac) {
        if (my_strlen(av[i]) > 0 && av[i][0] == '-')
            get_mode(av[i], mode, assert_flag);
        i += 1;
    }
}