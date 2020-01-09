/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** assert_mode.c
*/

#include "my_ls.h"

void flag_l(flags_t *mode)
{
    mode->flag_l = 1;
}

void flag_upper_r(flags_t *mode)
{
    mode->flag_upper_r = 1;
}

void flag_d(flags_t *mode)
{
    mode->flag_d = 1;
}

void flag_lower_r(flags_t *mode)
{
    mode->flag_lower_r = 1;
}

void flag_t(flags_t *mode)
{
    mode->flag_t = 1;
}