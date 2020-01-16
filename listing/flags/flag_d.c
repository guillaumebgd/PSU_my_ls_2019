/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** only prints the actual dir of a dir or a file
*/

#include "my_ls.h"
#include "my.h"
#include <stdlib.h>

static int get_arg_file_info(file_list_t **tmp,
                            const char *pathway,
                            int *index_issue)
{
    file_list_t *node = malloc(sizeof(file_list_t));

    if (!node) {
        *index_issue = 84;
        return (84);
    }
    if (fill_node_info(&node, pathway, index_issue) == 84)
        return (84);
    (*tmp) = node;
    return (0);
}

static void add_file(file_list_t **head, const char *pathway,
                        int *index_issue)
{
    file_list_t *new_node = malloc(sizeof(file_list_t));

    if (!(*head) || !new_node) {
        *index_issue = 84;
        return;
    }
    new_node->pathway = my_strdup(pathway);
    new_node->next = NULL;
    if (get_arg_file_info(&new_node, pathway, index_issue) == 84)
        return;
    new_node->next = (*head);
    new_node->prev = (*head)->prev;
    (*head)->prev->next = new_node;
    (*head)->prev = new_node;
}

static void add_first_file(list_file_list_t **list_directories,
                            const char *pathway, int *index_issue)
{
    list_file_list_t *new_node = malloc(sizeof(list_file_list_t));

    if (!new_node) {
        *index_issue = 84;
        return;
    }
    new_node->pathway = my_strdup(pathway);
    new_node->head = malloc(sizeof(file_list_t));
    if (!(new_node->head)) {
        *index_issue = 84;
        return;
    }
    if (get_arg_file_info(&new_node->head, pathway, index_issue) == 84)
        return;
    new_node->next = NULL;
    new_node->head->next = new_node->head;
    new_node->head->prev = new_node->head;
    (*list_directories) = new_node;
}

void flag_directory(list_file_list_t **list_directories,
                    const int ac, const char * const *av,
                    int *index_issue)
{
    int i = 0;

    if (!av || ac <= 0 || check_for_path(ac, av) == 1) {
        add_first_file(list_directories, ".", index_issue);
        return;
    }
    while (av[i] && i < ac) {
        if (av[i][0] != '-') {
            if (!(*list_directories))
                add_first_file(list_directories, av[i], index_issue);
            else
                add_file(&(*list_directories)->head, av[i], index_issue);
        }
        i += 1;
    }
}