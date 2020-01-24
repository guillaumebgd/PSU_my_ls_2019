/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** header for my_ls program
*/

#ifndef MY_LS_H_

#define MY_LS_H_

#include <sys/stat.h>
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#include <dirent.h>

typedef enum boolean_e {
    BANNED = 2,
    TRUE = 1,
    FALSE = 0
} boolean;

typedef enum types_e {
    DIR_FILE,
    REG_FILE
} types;

typedef struct flags_s {
    boolean flag_l;
    boolean flag_upper_r;
    boolean flag_d;
    boolean flag_lower_r;
    boolean flag_t;
} flags_t;

typedef struct setup_node_s {
    flags_t mode;
    int index_issue;
} setup_node_t;

typedef struct mode_fcter_arr_s {
    void (*fct_arr)(flags_t *);
} mode_fcter_arr_t;

typedef struct file_list_s {
    char *symlink_ptr_name;
    char *pathway;
    char *name;
    struct stat file_stat;
    gid_t grp_info;
    uid_t pwd;
    types file_type;
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

//flag functions
void flag_l(flags_t *mode);
void flag_upper_r(flags_t *mode);
void flag_d(flags_t *mode);
void flag_lower_r(flags_t *mode);
void flag_t(flags_t *mode);

//flag handling
void print_flag_l(file_list_t *tmp);
void print_time(file_list_t *tmp);
void apply_lower_r(file_list_t **head);
void swap_stats(file_list_t **first, file_list_t **second);
void flag_directory(list_file_list_t **list_directories,
                    const int ac, const char * const *av,
                    int *index_issue);
int fill_node_info(file_list_t **node,
                    const char *pathway,
                    int *index_issue);
void sort_names(file_list_t **head);
void sort_last_edit(file_list_t **head);

//main compute functions
int my_ls(const int ac, const char * const *av);
void print_ls(file_list_t **head, flags_t mode, boolean *sort_recursive);

//compute informations
void fill_list_directories(list_file_list_t **head,
                            const int ac, const char * const *av,
                            setup_node_t *noder);
int fill_mode(flags_t *mode, const int ac, const char * const *av);
void check_for_subdirectories(file_list_t **head, flags_t mode);
int check_for_path(const int ac, const char * const *av);

//linked lists handling
int create_file_list(file_list_t **head, const char *pathway,
                        setup_node_t *noder);
void add_first_file_list(list_file_list_t **list_directories,
                        const char *pathway, setup_node_t *noder);
void add_file_list(list_file_list_t **list_directories,
                    const char *pathway, setup_node_t *noder);
void directory_error(const int error, const char *pathway, int *index_issue);
void free_list_dir(list_file_list_t **head);
void free_file_list_t(file_list_t **head);

#endif /* MY_LS_H_ */