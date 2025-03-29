/*
** EPITECH PROJECT, 2022
** mysh.c
** File description:
** mysh
*/

#include <signal.h>
#include <string.h>
#include "minishell.h"

static void sig_handler(int _)
{
    my_printf("\n$> ");
}

static void redirect_action(char *buffer, shell_t *my_shell)
{
    if ((buffer[0] == '.' && buffer[1] == '/') || buffer[0] == '/')
        execut_file(buffer, my_shell);
    else
        do_cmd(buffer, my_shell);
    buffer[0] = '\0';
    return;
}

static shell_t *fill_struct_shell(char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));

    shell->env = env;
    shell->last_path = malloc(sizeof(char) * 200);
    get_all_folder(env, shell);
    shell->pid_father = getpid();
    getcwd(shell->last_path, 200);
    shell->set_new_last_path = 1;
    return shell;
}

static void main_loop(int ac, char **env)
{
    shell_t *my_shell = fill_struct_shell(env);
    char *buffer = malloc(sizeof(char) * 300);
    int res_read = 0;

    while (1 && ac == 1) {
        my_printf("$> ");
        while (res_read == 0) {
            signal(SIGINT, sig_handler);
            res_read = handle_input(buffer);
        }
        buffer[res_read - 1] = '\0';
        redirect_action(buffer, my_shell);
        res_read = 0;
    }
    free(buffer);
    return;
}

int main(int ac, char **av, char **env)
{
    if (ac == 1) {
        main_loop(ac, env);
        return 0;
    }
    display_error("Too much arguments.\n");
    return 84;
}
