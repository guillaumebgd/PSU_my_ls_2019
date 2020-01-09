/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** init_modes.c
*/

#include "my_ls.h"

void init_mode(flags_t *mode)
{
    mode->flag_l = 0;
    mode->flag_upper_r = 0;
    mode->flag_d = 0;
    mode->flag_lower_r = 0;
    mode->flag_t = 0;
}