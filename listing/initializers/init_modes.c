/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** init_modes.c
*/

#include "my_ls.h"

void init_mode(flags_t *mode)
{
    mode->flag_l = FALSE;
    mode->flag_upper_r = FALSE;
    mode->flag_d = FALSE;
    mode->flag_lower_r = FALSE;
    mode->flag_t = FALSE;
}