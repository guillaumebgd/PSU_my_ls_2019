/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** get_info.c
*/

#include "my_ls.h"
#include "my.h"
#include <stdlib.h>

static void several_arguments(int ac, char **av, file_list_t **head)
{
    unsigned int found_pathway = 0;
    unsigned int i = 0;

    while (i < (unsigned int)ac) {
        if (my_strlen(av[i]) > 0 && av[i][0] != '-') {
            create_file_list(head, av[i]);
            found_pathway = 1;
        }
        i += 1;
    }
    if (found_pathway == 0)
        create_file_list(head, "./");
}

void get_info(int ac, char **av, file_list_t **head, flags_t *mode)
{
    mode_fcter_arr_t *assert_flag = NULL;

    assert_flag = initialize_assert_flag();
    if (assert_flag == NULL)
        return;
    fill_mode(ac, av, mode, assert_flag);
    free(assert_flag);
    if (ac == 0) {
        create_file_list(head, "./");
        return;
    }
    several_arguments(ac, av, head);
}