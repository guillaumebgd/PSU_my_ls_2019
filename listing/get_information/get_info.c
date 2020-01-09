/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** get_info.c
*/

#include "my_ls.h"
#include "my.h"
#include <stdlib.h>

void get_info(int ac, char **av, file_list_t **head, flags_t *mode)
{
    mode_fcter_arr_t *assert_flag = NULL;
    unsigned int i = 0;

    assert_flag = initialize_assert_flag();
    if (assert_flag == NULL)
        return;
    fill_mode(ac, av, mode, assert_flag);
    free(assert_flag);
    if (ac == 0) {
        create_file_list(head, "./");
        return;
    }
    while (i < (unsigned int)ac) {
        if (av[i][0] != '-')
            create_file_list(head, av[i]);
        i += 1;
    }
}