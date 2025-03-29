/*
** EPITECH PROJECT, 2022
** gest_error.c
** File description:
** gest_error
*/

#include "minishell.h"

void display_error(char *str)
{
    int len = my_strlen(str);

    write(2, str, len);
}

int gest_error_file(char *path)
{
    int exist = access(path, F_OK);
    int execut = access(path, X_OK);

    if (exist == -1) {
        display_error(path);
        display_error(": Command not found.\n");
        return -1;
    } else if (execut == -1) {
        display_error(path);
        display_error(": Permission denied.\n");
        return -1;
    }
    return 0;
}

void handle_segfault(int status)
{
    if (status == 139) {
        display_error("Segmentation fault (core dumped)\n");
        exit(139);
    }
    return;
}