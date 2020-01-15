/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** main fuction of the program
*/

#include "my_ls.h"

int main(const int ac, const char * const *av)
{
    if (ac <= 0 || !av)
        return (84);
    return (my_ls(ac, av));
}