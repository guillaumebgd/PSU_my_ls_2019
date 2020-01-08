/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls.h
*/

#ifndef MY_LS_H_

#define MY_LS_H_

#include <stdarg.h>

typedef struct flags_s {
    unsigned int flag_l;
    unsigned int flag_upper_r;
    unsigned int flag_d;
    unsigned int flag_lower_r;
    unsigned int flag_t;
} flags_t;

void single_arg(const char *);
void handle_second_arg(char **);

void sort_stock_files(char ***, const unsigned int);

#endif /* MY_LS_H_ */