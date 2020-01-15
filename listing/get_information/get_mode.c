/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** gets flags given in arguments
*/

#include "my_ls.h"
#include "my.h"
#include <stdlib.h>

static void get_mode(mode_fcter_arr_t *assert_flag,
                    flags_t *mode,
                    const char *argument)
{
    const char flags[] = "lRdrt";
    int len_argument = my_strlen(argument);
    int cmp = 0;
    int i = 1;

    if (len_argument <= 0)
        return;
    while (i < len_argument) {
        while (flags[cmp] != '\0') {
            if (argument[i] == flags[cmp])
                assert_flag[cmp].fct_arr(mode);
            cmp += 1;
        }
        cmp = 0;
        i += 1;
    }
}

int fill_mode(int ac, char **av, flags_t *mode)
{
    mode_fcter_arr_t *assert_flag = NULL;
    int i = 0;

    assert_flag = initialize_assert_flag();
    if (!assert_flag)
        return (84);
    init_mode(mode);
    while (i < ac) {
        if (my_strlen(av[i]) > 0 && av[i][0] == '-')
            get_mode(assert_flag, mode, av[i]);
        i += 1;
    }
    free(assert_flag);
    return (0);
}