/*
** EPITECH PROJECT, 2019
** library
** File description:
** my.h
*/

#ifndef MY_H_

#define MY_H_

int my_putchar(int, const char);

int my_strlen(char const *);
int my_putstr(int, char const *);

unsigned int my_is_uppercase(const char);
int my_strcmp(char *, char *);
char *my_strdup(char const *);
char *my_strcat(char const *, char const *);
void my_str_swap(char **, char **);

void my_put_nbr(int, int, char const *, unsigned int);

#endif /* MY_H_ */