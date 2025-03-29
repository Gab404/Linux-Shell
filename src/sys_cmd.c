/*
** EPITECH PROJECT, 2022
** sys_cmd.c
** File description:
** sys_cmd
*/

#include "minishell.h"

void get_exit(char *buffer)
{
    if (my_strcmp(buffer, "exit") == 0) {
        my_printf("exit\n");
        exit(0);
    }
}