/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** main fuction of the program
*/

#include "my_ls.h"
#include <stddef.h>

int main(int ac, char **av)
{
    if (ac <= 0 || !av)
        return (84);
    return (my_ls(ac, av));
}