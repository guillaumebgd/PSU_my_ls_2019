/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** test_get_info.c
*/

#include "my_ls.h"
#include "my.h"
#include <criterion/criterion.h>

Test(get_info, normal_test)
{
    char *argv[] = {"-l", "-R", "-d"};
    file_list_t *head = NULL;
    flags_t mode;

    get_info(3, argv, &head, &mode);
    if (mode.flag_l == 1 && mode.flag_upper_r == 1
        && mode.flag_d == 1 && mode.flag_lower_r == 0
        && mode.flag_t == 0)
        cr_assert_eq(1, 1);
    else
        cr_assert_eq(1, 2);
}

Test(get_info, concat_test)
{
    char *argv[] = {"-lrR"};
    file_list_t *head = NULL;
    flags_t mode;

    get_info(1, argv, &head, &mode);
    if (mode.flag_l == 1 && mode.flag_upper_r == 1
        && mode.flag_d == 0 && mode.flag_lower_r == 1
        && mode.flag_t == 0)
        cr_assert_eq(1, 1);
    else
        cr_assert_eq(1, 2);
}

Test(get_info, normal_check_list_files)
{
    char *argv[] = {"-lrR", "./include"};
    char *cmp[] = {"my.h", "my_ls.h"};
    unsigned int i = 0;
    file_list_t *head = NULL;
    file_list_t *tmp = NULL;
    flags_t mode;

    get_info(2, argv, &head, &mode);
    tmp = head;
    while (tmp != head->prev) {
        if (my_strcmp(tmp->name, cmp[i]) != 0)
            cr_assert_eq(1, 2);
        tmp = tmp->next;
        i += 1;
    }
    cr_assert_eq(1, 1);
}