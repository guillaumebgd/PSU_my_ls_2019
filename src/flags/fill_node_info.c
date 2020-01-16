/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** fill information needed for a node for -d flag
*/

#include "my_ls.h"
#include "my.h"
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

static int check_for_symb_link(file_list_t **node, const char *pathway,
                                int *index_issue)
{
    size_t size = 0;

    if (S_ISLNK((*node)->file_stat.st_mode)) {
        (*node)->symlink_ptr_name = malloc(sizeof(char) * 4097);
        if (!((*node)->symlink_ptr_name)) {
            *index_issue = 84;
            return (84);
        }
        size = readlink(pathway, (*node)->symlink_ptr_name, 4096);
        (*node)->symlink_ptr_name[size] = '\0';
    }
}

int fill_node_info(file_list_t **node,
                    const char *pathway,
                    int *index_issue)
{
    (*node)->name = my_strdup(pathway);
    (*node)->symlink_ptr_name = NULL;
    (*node)->sub_dir = NULL;
    (*node)->pathway = my_strdup(pathway);
    if (lstat(pathway, &(*node)->file_stat) < 0) {
        directory_error(errno, pathway, index_issue);
        return (84);
    }
    if (check_for_symb_link(node, pathway, index_issue) == 84)
        return (84);
    (*node)->grp_info = (*node)->file_stat.st_gid;
    (*node)->pwd = (*node)->file_stat.st_uid;
    return (0);
}