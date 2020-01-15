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
#include <unistd.h>

static int get_file_path(char **file_path,
                        const char *d_name,
                        const char *pathway)
{
    if (pathway[my_strlen(pathway) - 1] == '/') {
        (*file_path) = my_strcat(pathway, d_name);
        return ((*file_path)) ? 0 : 84;
    }
    (*file_path) = my_strcat(my_strcat(pathway, "/"), d_name);
    return ((*file_path)) ? 0 : 84;
}

static void init_nodes_values(file_list_t *node,
                            struct dirent *dir_stat,
                            char *file_path)
{
    size_t size = 0;

    node->name = my_strdup(dir_stat->d_name);
    node->symlink_ptr_name = NULL;
    node->sub_dir = NULL;
    node->pathway = my_strdup(file_path);
    lstat(file_path, &node->file_stat);
    if (S_ISLNK(node->file_stat.st_mode)) {
        node->symlink_ptr_name = malloc(sizeof(char) * 4097);
        size = readlink(file_path, node->symlink_ptr_name, 4096);
        node->symlink_ptr_name[size] = '\0';
    }
    if (S_ISDIR(node->file_stat.st_mode))
        create_file_list(&node->sub_dir, file_path);
    free(file_path);
    node->grp_info = node->file_stat.st_gid;
    node->pwd = node->file_stat.st_uid;
}

static file_list_t *add_node(file_list_t **head,
                            struct dirent *dir_stat,
                            const char *pathway)
{
    file_list_t *new_node = malloc(sizeof(file_list_t));
    char *file_path = NULL;

    if (get_file_path(&file_path, dir_stat->d_name, pathway) == 84) {
        if (new_node != NULL)
            free(new_node);
        return (NULL);
    } if (new_node == NULL) {
        free(file_path);
        return (NULL);
    }
    init_nodes_values(new_node, dir_stat, file_path);
    new_node->next = (*head);
    new_node->prev = (*head)->prev;
    (*head)->prev->next = new_node;
    (*head)->prev = new_node;
    return (new_node);
}

static file_list_t *add_first_node(file_list_t **head,
                                    struct dirent *dir_stat,
                                    const char *pathway)
{
    file_list_t *new_node = malloc(sizeof(file_list_t));
    char *file_path = NULL;

    if (get_file_path(&file_path, dir_stat->d_name, pathway) == 84) {
        if (new_node != NULL)
            free(new_node);
        return (NULL);
    }
    if (new_node == NULL) {
        free(file_path);
        return (NULL);
    }
    init_nodes_values(new_node, dir_stat, file_path);
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
            add_first_node(head, dir_stat, pathway);
        else if (dir_stat->d_name[0] != '.')
            add_node(head, dir_stat, pathway);
        dir_stat = readdir(directory);
    }
    closedir(directory);
    return (0);
}