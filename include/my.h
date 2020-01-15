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
char *my_strdup(const char *template);
char *my_strcat(const char *first, const char *second);
void my_str_swap(char **first, char **second);
int my_int_size(const int nb);
void my_put_nbr(int fd, long int nb, const char *base, unsigned int len_base);
int my_getnbr(const char *str);

#endif /* MY_H_ */