/*
** EPITECH PROJECT, 2019
** PSU_my_ls_bootstrap_2019
** File description:
** my.h
*/

#ifndef MY_H_

#define MY_H_

#include <stdarg.h>

int my_printf(char const *, ...);

void my_put_nbr(int, char const *, unsigned int, int *);
void my_put_uns_nbr(unsigned int, char const *, unsigned int, int *);
void my_put_nbr_long(long int, char const *, long unsigned int, int *);
void my_put_nbr_long_long(long long int, char const *,
                            long long unsigned int, int *);
void my_put_uns_nbr_long(long unsigned int, char const *,
                            long unsigned int, int *);
void my_put_uns_nbr_long_long(long long unsigned int,
                            char const *,
                            long long unsigned int,
                            int *);
void my_put_nbr_short(short int, char const *, short unsigned int, int *);
void my_put_uns_nbr_short(short unsigned int, char const *,
                            short unsigned int, int *);
void my_put_address(long unsigned int, char const *, unsigned int, int *);
void my_putchar(char);
int my_getnbr(char const *);
int my_putstr(char const *, int *);
int my_strlen(char const *);
int my_int_size(int, int);
int my_strncmp(const char *, const char *);

#endif /* MY_H_ */