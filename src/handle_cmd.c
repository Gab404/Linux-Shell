/*
** EPITECH PROJECT, 2022
** handle_cmd.c
** File description:
** handle_cmd
*/

#include <string.h>
#include "minishell.h"

void execut_cmd(shell_t *my_shell)
{
    pid_t pid;
    int status;
    char *path = get_good_path(my_shell->all_folder, my_shell->command[0]);

    if (path != NULL) {
        pid = fork();
        if (my_shell->pid_father != getpid()) {
            execve(path, my_shell->command, my_shell->env);
        } else {
            wait(&status);
            handle_segfault(status);
            path = NULL;
        }
    }
    return;
}

void second_cut(int nb_word, shell_t *my_shell, int j)
{
    int len;
    char *tmp_str;

    for (int i = 0; i != nb_word; i++, my_shell->all_action[j] = NULL) {
        tmp_str = strtok(my_shell->all_action[j], "; \t");
        if (tmp_str == NULL) {
            my_shell->already_all_action[j][nb_word] = NULL;
            break;
        }
        len = my_strlen(tmp_str);
        my_shell->already_all_action[j][i] = malloc(sizeof(char) * (len + 1));
        my_strcpy(my_shell->already_all_action[j][i], tmp_str);
        my_shell->already_all_action[j][i][len] = '\0';
    }
    return;
}

void cut_all_command(int nb, shell_t *my_shell)
{
    int nb_w;

    my_shell->already_all_action = malloc(sizeof(char **) * (nb + 1));
    for (int j = 0; j != nb; j++) {
        nb_w = real_get_nb_word(my_shell->all_action[j], ' ');
        my_shell->already_all_action[j] = malloc(sizeof(char *) * (nb_w + 1));
        second_cut(nb_w, my_shell, j);
        my_shell->already_all_action[j][nb_w] = NULL;
    }
    return;
}

void fill_command(int nb_action, char *buffer, shell_t *my_shell)
{
    char *reset_buffer = buffer;

    if (nb_action == 1)
        handle_buffer(reset_buffer, get_nb_word(buffer, ' ', ';'), my_shell);
    else {
        get_all_command(nb_action, my_shell, buffer);
        cut_all_command(nb_action, my_shell);
    }
    return;
}

void do_cmd(char *buffer, shell_t *my_shell)
{
    int executed_cmd = 0;
    int nb_action = real_get_nb_word(buffer, ';');

    fill_command(nb_action, buffer, my_shell);
    for (int i = 0; i < nb_action; i++) {
        if (nb_action > 1)
            my_shell->command = my_shell->already_all_action[i];
        get_exit(buffer);
        get_cd(&executed_cmd, my_shell);
        if (executed_cmd == 0)
            get_unsetenv(my_shell, &executed_cmd);
        if (executed_cmd == 0)
            get_setenv(&executed_cmd, my_shell);
        if (executed_cmd == 0)
            execut_cmd(my_shell);
        executed_cmd = 0;
    }
}