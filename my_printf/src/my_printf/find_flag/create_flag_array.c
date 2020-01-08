/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** create_flag_array.c
*/

#include "my_printf.h"
#include <stdlib.h>

void initialize_modifiers(arr_ptr *array_ptr)
{
    array_ptr->list_mod = malloc(sizeof(mod_checker) * 4);
    if (array_ptr->list_mod == NULL)
        return;
    array_ptr->list_mod[0].mod_list = &mod_hashtag;
    array_ptr->list_mod[1].mod_list = &mod_short;
    array_ptr->list_mod[2].mod_list = &mod_long;
    array_ptr->list_mod[3].mod_list = &mod_long;
}

void initialize_path_taker(arr_ptr *array_ptr)
{
    array_ptr->list_redir = malloc(sizeof(path_taker) * 11);
    if (array_ptr->list_redir == NULL)
        return;
    array_ptr->list_redir[0].flag_list = &flag_c;
    array_ptr->list_redir[1].flag_list = &flag_d;
    array_ptr->list_redir[2].flag_list = &flag_i;
    array_ptr->list_redir[3].flag_list = &flag_u;
    array_ptr->list_redir[4].flag_list = &flag_b;
    array_ptr->list_redir[5].flag_list = &flag_o;
    array_ptr->list_redir[6].flag_list = &flag_lower_x;
    array_ptr->list_redir[7].flag_list = &flag_upper_x;
    array_ptr->list_redir[8].flag_list = &flag_lower_s;
    array_ptr->list_redir[9].flag_list = &flag_upper_s;
    array_ptr->list_redir[10].flag_list = &flag_p;
}