/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** redirection to assert a flag value if found
*/

#include "my_ls.h"

void flag_l(flags_t *mode)
{
    mode->flag_l = TRUE;
}

void flag_upper_r(flags_t *mode)
{
    if (mode->flag_upper_r == FALSE)
        mode->flag_upper_r = TRUE;
}

void flag_d(flags_t *mode)
{
    mode->flag_d = TRUE;
    mode->flag_upper_r = BANNED;
}

void flag_lower_r(flags_t *mode)
{
    mode->flag_lower_r = TRUE;
}

void flag_t(flags_t *mode)
{
    mode->flag_t = TRUE;
}