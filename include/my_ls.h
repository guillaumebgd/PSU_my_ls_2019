/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** header for my_ls
*/

#ifndef MY_LS_H_

#define MY_LS_H_

#include <sys/stat.h>
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#include <dirent.h>

typedef enum BOOLEAN_E {
    TRUE = 1,
    FALSE = 0
} BOOLEAN;

typedef struct flags_s {
    BOOLEAN flag_l;
    BOOLEAN flag_upper_r;
    BOOLEAN flag_d;
    BOOLEAN flag_lower_r;
    BOOLEAN flag_t;
} flags_t;

typedef struct mode_fcter_arr_s {
    void (*fct_arr)(flags_t *);
} mode_fcter_arr_t;

typedef struct file_list_s {
    struct stat file_stat;
    gid_t grp_info;
    uid_t pwd;
    char *name;
    struct file_list_s *next;
    struct file_list_s *prev;
} file_list_t;

typedef struct list_file_list_s {
    file_list_t *head;
    char *pathway;
    struct list_file_list_s *next;
} list_file_list_t;

//initializers
void init_mode(flags_t *);
mode_fcter_arr_t *initialize_assert_flag(void);

//compute informations
void get_info(int, char **, file_list_t **, flags_t *);
void fill_list_directories(list_file_list_t **,
                            const int, const char * const *);
int fill_mode(int, const char * const *, flags_t *);

//flag functions
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

//main compute functions
int my_ls(const int ac, const char * const *av);
void print_ls(file_list_t **, flags_t);

void swap_stats(file_list_t **, file_list_t **);
void sort_names(file_list_t **);
void sort_last_edit(file_list_t **);

void free_file_list_t(file_list_t **);

#endif /* MY_LS_H_ */