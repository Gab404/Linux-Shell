/*
** EPITECH PROJECT, 2022
** execut_file.c
** File description:
** execut_file
*/

#include "minishell.h"

void execut_file(char *buffer, shell_t *my_shell)
{
    int status;
    pid_t pid;
    int nb_arg = real_get_nb_word(buffer, ' ');
    int error;

    handle_buffer(buffer, nb_arg, my_shell);
    error = gest_error_file(my_shell->command[0]);
    if (error == 0) {
        pid = fork();
        if (my_shell->pid_father != getpid()) {
            my_show_word_array(my_shell->command);
            execve(my_shell->command[0], my_shell->command, my_shell->env);
        } else {
            wait(&status);
            handle_segfault(status);
        }
    }
}
