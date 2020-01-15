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
    char *argv[] = {"./my_ls", "./listing/flags/"};

    cr_redirect_stdout();
    my_ls(2, (const char * const *)argv);
    cr_assert_stdout_eq_str("flag_l.c\n"
                            "flag_lower_r.c\n"
                            "print_time.c\n");
}

Test(my_ls, simple_my_ls_only_reverse_flag)
{
    char *argv[] = {"./my_ls", "-r", "./listing/flags/"};

    cr_redirect_stdout();
    my_ls(3, (const char * const *)argv);
    cr_assert_stdout_eq_str("print_time.c\n"
                            "flag_lower_r.c\n"
                            "flag_l.c\n");
}