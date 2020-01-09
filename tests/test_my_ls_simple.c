/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** test_my_ls_simple.c
*/

#include "my_ls.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_ls, simple_my_ls_no_flag)
{
    char *argv[] = {"./my_ls", "./listing/flags"};
    file_list_t *head = NULL;
    flags_t mode;

    cr_redirect_stdout();
    get_info(1, &argv[1], &head, &mode);
    my_ls(&head, mode);
    free_list(&head);
    cr_assert_stdout_eq_str("flag_l.c\n"
                            "flag_lower_r.c\n");
}

Test(my_ls, simple_my_ls_only_reverse_flag)
{
    char *argv[] = {"./my_ls", "-r", "./listing/flags/"};
    file_list_t *head = NULL;
    flags_t mode;

    cr_redirect_stdout();
    get_info(2, &argv[1], &head, &mode);
    my_ls(&head, mode);
    free_list(&head);
    cr_assert_stdout_eq_str("flag_lower_r.c\n"
                            "flag_l.c\n");
}