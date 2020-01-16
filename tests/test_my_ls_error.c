/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** tests basic errors of my_ls
*/

#include "my_ls.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_ls, no_file_directory)
{
    char *argv[] = {"./my_ls", "./abcjajejejaekae/"};

    cr_assert_eq(my_ls(2, (const char * const *)argv), 84);
}

Test(my_ls, no_perms)
{
    char *argv[] = {"./my_ls", "/root/"};

    cr_assert_eq(my_ls(2, (const char * const *)argv), 84);
}