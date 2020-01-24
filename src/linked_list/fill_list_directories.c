/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** computes files given into args into linked lists
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_ls.h"
#include "my.h"

static void assert_file(file_list_t **node, const char *pathway,
                        setup_node_t *noder)
{
    size_t size = 0;

    *node = malloc(sizeof(file_list_t));
    if (!(*node))
        return;
    (*node)->name = my_strdup(pathway);
    (*node)->symlink_ptr_name = NULL;
    (*node)->sub_dir = NULL;
    (*node)->pathway = my_strdup(pathway);
    lstat(pathway, &(*node)->file_stat);
    (*node)->file_type = REG_FILE;
    if (S_ISLNK((*node)->file_stat.st_mode) && noder->mode.flag_l == TRUE) {
        (*node)->symlink_ptr_name = malloc(sizeof(char) * 4097);
        if (!((*node)->symlink_ptr_name))
            return;
        size = readlink(pathway, (*node)->symlink_ptr_name, 4096);
        (*node)->symlink_ptr_name[size] = '\0';
    }
    (*node)->grp_info = (*node)->file_stat.st_gid;
    (*node)->pwd = (*node)->file_stat.st_uid;
}

void add_file(list_file_list_t **list_directories,
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
    assert_file(&(new_node->head), pathway, noder);
    new_node->next = NULL;
    new_node->head->next = new_node->head;
    new_node->head->prev = new_node->head;
    tmp->next = new_node;
}

void add_first_file(list_file_list_t **list_directories,
                    const char *pathway, setup_node_t *noder)
{
    list_file_list_t *new_node = malloc(sizeof(list_file_list_t));

    if (!new_node) {
        noder->index_issue = 84;
        return;
    }
    new_node->pathway = my_strdup(pathway);
    new_node->head = NULL;
    assert_file(&(new_node->head), pathway, noder);
    new_node->next = NULL;
    new_node->head->next = new_node->head;
    new_node->head->prev = new_node->head;
    (*list_directories) = new_node;
}

static void check_file_dir(list_file_list_t **list_directories,
                        const char *pathway, setup_node_t *noder)
{
    struct stat file_stat;
    int i = 0;

    i = stat(pathway, &file_stat);
    if (!(*list_directories)) {
        if (S_ISDIR(file_stat.st_mode) || i < 0)
            add_first_file_list(list_directories, pathway, noder);
        else
            add_first_file(list_directories, pathway, noder);
    } else {
        if (S_ISDIR(file_stat.st_mode) || i < 0)
            add_file_list(list_directories, pathway, noder);
        else
            add_file(list_directories, pathway, noder);
    }
}

void fill_list_directories(list_file_list_t **list_directories,
                        const int ac, const char * const *av,
                        setup_node_t *noder)
{
    int i = 0;

    if (!av || ac <= 0 || check_for_path(ac, av) == 1) {
        add_first_file_list(list_directories, ".", noder);
        return;
    }
    while (av[i] && i < ac) {
        if (av[i][0] != '-')
            check_file_dir(list_directories, av[i], noder);
        i += 1;
    }
}