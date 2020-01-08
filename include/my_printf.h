/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** header to link files with lib my
*/

#ifndef MY_PRINTF_H_

#define MY_PRINTF_H_

#include <stdarg.h>

typedef struct counters_s {
    int printed_char;
    int i;
} counters_t;

typedef struct redirect_array {
    void (*flag_list)(va_list, counters_t *);
} path_taker;

typedef struct mod_redirect {
    void (*mod_list)(char const *, counters_t *, va_list);
} mod_checker;

typedef struct arr_ptr_s {
    path_taker *list_redir;
    mod_checker *list_mod;
} arr_ptr;

int get_flag(char const *, arr_ptr *, counters_t *, va_list);
int check_for_flag(char);
int check_for_mod(char);
int check_base(char);

void flag_c(va_list, counters_t *);
void flag_d(va_list, counters_t *);
void flag_i(va_list, counters_t *);
void flag_u(va_list, counters_t *);
void flag_b(va_list, counters_t *);
void flag_o(va_list, counters_t *);
void flag_lower_x(va_list, counters_t *);
void flag_upper_x(va_list, counters_t *);
void flag_lower_s(va_list, counters_t *);
void flag_upper_s(va_list, counters_t *);
void flag_p(va_list, counters_t *);

void mod_hashtag(char const *, counters_t *, va_list);
void mod_plus(char const *, counters_t *, va_list);

void print_plus(char const *, int, char);
int get_nb_char_to_print(char, char const *);
int get_base(char const *);

void mod_minus(char const *, counters_t *, va_list);
void mod_long(char const *, counters_t *, va_list);
void mod_short(char const *, counters_t *, va_list);

void flag_percent(char const *, counters_t *);

void initialize_modifiers(arr_ptr *);
void initialize_path_taker(arr_ptr *);

#endif /* MY_PRINTF_H_ */