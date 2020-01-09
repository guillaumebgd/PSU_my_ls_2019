/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** init_assert_mode.c
*/

#include "my_ls.h"
#include <stdlib.h>

mode_fcter_arr_t *initialize_assert_flag(void)
{
    mode_fcter_arr_t *assert_flag = malloc(sizeof(mode_fcter_arr_t) * 5);

    if (assert_flag == NULL)
        return (NULL);
    assert_flag[0].fct_arr = &flag_l;
    assert_flag[1].fct_arr = &flag_upper_r;
    assert_flag[2].fct_arr = &flag_d;
    assert_flag[3].fct_arr = &flag_lower_r;
    assert_flag[4].fct_arr = &flag_t;
    return (assert_flag);
}