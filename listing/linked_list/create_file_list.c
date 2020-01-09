/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** creates a circular doubly linked list of files
*/

#include "my_ls.h"
#include "my.h"
#include <stdlib.h>
#include <errno.h>

static file_list_t *add_node(file_list_t **head,
                            struct dirent *dir_stat)
{
    file_list_t *new_node = malloc(sizeof(file_list_t));

    if (new_node == NULL)
        return (NULL);
    new_node->name = my_strdup(dir_stat->d_name);
    new_node->next = (*head);
    new_node->prev = (*head)->prev;
    (*head)->prev->next = new_node;
    (*head)->prev = new_node;
    return (new_node);
}

static file_list_t *add_first_node(file_list_t **head,
                                    struct dirent *dir_stat)
{
    file_list_t *new_node = malloc(sizeof(file_list_t));

    if (new_node == NULL)
        return (NULL);
    new_node->name = my_strdup(dir_stat->d_name);
    new_node->next = new_node;
    new_node->prev = new_node;
    (*head) = new_node;
    return (new_node);
}

int create_file_list(file_list_t **head, const char *pathway)
{
    struct dirent *dir_stat = NULL;
    DIR *directory = NULL;

    directory = opendir(pathway);
    if (directory == NULL) {
        directory_error(errno, pathway);
        return (84);
    }
    dir_stat = readdir(directory);
    while (dir_stat != NULL) {
        if ((*head) == NULL && dir_stat->d_name[0] != '.')
            add_first_node(head, dir_stat);
        else if (dir_stat->d_name[0] != '.')
            add_node(head, dir_stat);
        dir_stat = readdir(directory);
    }
    closedir(directory);
    return (0);
}