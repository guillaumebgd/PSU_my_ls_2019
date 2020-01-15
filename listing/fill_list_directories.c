/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** computes files given into args into linked lists
*/

#include "my_ls.h"
#include "my.h"
#include <stdlib.h>

static void add_file_list(list_file_list_t **list_directories,
                            const char *pathway)
{
    list_file_list_t *new_node = malloc(sizeof(list_file_list_t));
    list_file_list_t *tmp = NULL;

    if (!(*list_directories) || !new_node)
        return;
    tmp = (*list_directories);
    while (tmp->next)
        tmp = tmp->next;
    new_node->pathway = my_strdup(pathway);
    new_node->head = NULL;
    create_file_list(&new_node->head, pathway);
    new_node->next = NULL;
    tmp->next = new_node;
}

static void add_first_file_list(list_file_list_t **list_directories,
                                const char *pathway)
{
    list_file_list_t *new_node = malloc(sizeof(list_file_list_t));

    if (!new_node)
        return;
    new_node->pathway = my_strdup(pathway);
    new_node->head = NULL;
    create_file_list(&new_node->head, pathway);
    new_node->next = NULL;
    (*list_directories) = new_node;
}

void fill_list_directories(list_file_list_t **list_directories,
                        const int ac, const char * const *av)
{
    int i = 0;

    if (ac <= 0 || !av) {
        add_first_file_list(list_directories, ".");
        return;
    }
    while (av[i] && i < ac) {
        if (av[i][0] != '-') {
            if (!(*list_directories))
                add_first_file_list(list_directories, av[i]);
            else
                add_file_list(list_directories, av[i]);
        }
        i += 1;
    }
}