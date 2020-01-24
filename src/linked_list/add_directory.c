/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** add_directory.c
*/

#include "my_ls.h"
#include "my.h"
#include <stdlib.h>

void add_file_list(list_file_list_t **list_directories,
                    const char *pathway, setup_node_t *noder)
{
    list_file_list_t *new_node = malloc(sizeof(list_file_list_t));
    list_file_list_t *tmp = NULL;

    if (!(*list_directories) || !new_node) {
        noder->index_issue = 84;
        return;
    }
    tmp = (*list_directories);
    while (tmp->next)
        tmp = tmp->next;
    new_node->pathway = my_strdup(pathway);
    new_node->head = NULL;
    if (create_file_list(&new_node->head, pathway, noder) == 84)
        return;
    new_node->next = NULL;
    tmp->next = new_node;
}

void add_first_file_list(list_file_list_t **list_directories,
                        const char *pathway, setup_node_t *noder)
{
    list_file_list_t *new_node = malloc(sizeof(list_file_list_t));

    if (!new_node) {
        noder->index_issue = 84;
        return;
    }
    new_node->pathway = my_strdup(pathway);
    new_node->head = NULL;
    if (create_file_list(&new_node->head, pathway, noder) == 84)
        return;
    new_node->next = NULL;
    (*list_directories) = new_node;
}

int check_for_path(const int ac, const char * const *av)
{
    int i = 0;

    while (av[i] && i < ac) {
        if (av[i][0] != '-')
            return (0);
        i += 1;
    }
    return (1);
}