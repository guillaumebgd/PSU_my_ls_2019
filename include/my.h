/*
** EPITECH PROJECT, 2019
** library
** File description:
** header for libmy
*/

#ifndef MY_H_

#define MY_H_

int my_putchar(const int fd, const char c);
int my_strlen(char const *str);
int my_putstr(const int fd, char const *str);
int my_is_uppercase(const char c);
int my_strcmp(const char *to_find, const char *template);
char *my_strdup(char const *);
char *my_strcat(char const *, char const *);
void my_str_swap(char **, char **);
int my_int_size(int);
void my_put_nbr(int, long int, char const *, unsigned int);
int my_getnbr(char const *);

#endif /* MY_H_ */