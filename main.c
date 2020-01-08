/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** main function
*/

#include "my_ls.h"

int main(int ac, char **av)
{
    if (ac == 1)
        single_arg("./");
    else
        single_arg(av[1]);
    //handle_second_arg(&av[1]);
    return (0);
}