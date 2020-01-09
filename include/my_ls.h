/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls.h
*/

#ifndef MY_LS_H_

#define MY_LS_H_

#include <sys/stat.h>
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#include <dirent.h>

typedef struct flags_s {
    unsigned int flag_l;
    unsigned int flag_upper_r;
    unsigned int flag_d;
    unsigned int flag_lower_r;
    unsigned int flag_t;
} flags_t;

typedef struct file_list_s {
    struct stat file_stat;
    struct group *grp_info;
    struct passwd *pwd;
    char *name;
    struct file_list_s *next;
    struct file_list_s *prev;
} file_list_t;

typedef struct mode_fcter_arr_s {
    void (*fct_arr)(flags_t *);
} mode_fcter_arr_t;

void init_mode(flags_t *);
mode_fcter_arr_t *initialize_assert_flag(void);

void get_info(int, char **, file_list_t **, flags_t *);
void fill_mode(int, char **, flags_t *, mode_fcter_arr_t *);

void flag_l(flags_t *);
void flag_upper_r(flags_t *);
void flag_d(flags_t *);
void flag_lower_r(flags_t *);
void flag_t(flags_t *);

int create_file_list(file_list_t **, const char *);
void directory_error(int, const char *);

void print_flag_l(file_list_t *);
void print_time(file_list_t *);
void apply_lower_r(file_list_t **);

void my_ls(file_list_t **, flags_t);

void swap_stats(struct stat *, struct stat *);
void sort_names(file_list_t **);

void free_list(file_list_t **);

#endif /* MY_LS_H_ */