/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** main function
*/

#include "my_ls.h"
#include <stddef.h>

int main(int ac, char **av)
{
    file_list_t *head = NULL;
    flags_t mode;

    if (ac == 1)
        get_info(0, NULL, &head, &mode);
    else
        get_info(ac, &av[1], &head, &mode);
    my_ls(&head);
    free_list(&head);
    return (0);
}