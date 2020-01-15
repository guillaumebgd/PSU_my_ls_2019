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
    char *pathway;
    char *symlink_ptr_name;
    struct file_list_s *sub_dir;
    struct file_list_s *next;
    struct file_list_s *prev;
} file_list_t;

typedef struct list_file_list_s {
    file_list_t *head;
    char *pathway;
    struct list_file_list_s *next;
} list_file_list_t;

//initializers
void init_mode(flags_t *mode);
mode_fcter_arr_t *initialize_assert_flag(void);

//compute informations
void fill_list_directories(list_file_list_t **head,
                            const int ac, const char * const *av);
int fill_mode(flags_t *mode, const int ac, const char * const *av);
void check_for_subdirectories(file_list_t **head, flags_t mode);

//flag functions
void flag_l(flags_t *mode);
void flag_upper_r(flags_t *mode);
void flag_d(flags_t *mode);
void flag_lower_r(flags_t *mode);
void flag_t(flags_t *mode);

int create_file_list(file_list_t **head, const char *pathway);
void directory_error(const int error, const char *pathway);

void print_flag_l(file_list_t *tmp);
void print_time(file_list_t *tmp);
void apply_lower_r(file_list_t **head);

//main compute functions
int my_ls(const int ac, const char * const *av);
void print_ls(file_list_t **head, flags_t mode);

void swap_stats(file_list_t **first, file_list_t **second);
void sort_names(file_list_t **head);
void sort_last_edit(file_list_t **head);

void free_list_dir(list_file_list_t **head);
void free_file_list_t(file_list_t **head);

#endif /* MY_LS_H_ */