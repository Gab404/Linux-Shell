/*
** EPITECH PROJECT, 2022
** setenv.c
** File description:
** setenv
*/

#include "minishell.h"

char *put_new_var(int nb_row, char **command, int len_name, int *len_value)
{
    char *new_var;

    if (nb_row == 3) {
        *len_value = my_strlen(command[2]);
        new_var = malloc(sizeof(char) * (len_name + *len_value + 2));
    } else
        new_var = malloc(sizeof(char) * (len_name + 2));
    return new_var;
}

void get_new_variable(char **command, int nb_row, char **new_env, int size_env)
{
    int len_name = my_strlen(command[1]);
    int len_value;
    char *new_variable;
    int i = 0;
    int j = 0;

    new_variable = put_new_var(nb_row, command, len_name, &len_value);
    for (; i < len_name; i++) {
        new_variable[i] = command[1][i];
    }
    new_variable[i] = '=';
    i++;
    while (nb_row == 3 && i < len_name + len_value + 1) {
        new_variable[i] = command[2][j];
        i++;
        j++;
    }
    new_variable[i] = '\0';
    new_env[size_env] = new_variable;
}

char **get_new_env(char **env, char **command, int i)
{
    char **new_env;
    int size_env = 0;

    while (env[size_env] != NULL) {
        size_env++;
    }
    new_env = malloc(sizeof(char *) * (size_env + 2));
    for (int i = 0; env[i] != NULL; i++) {
        new_env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        my_strcpy(new_env[i], env[i]);
    }
    get_new_variable(command, i, new_env, size_env);
    new_env[size_env + 1] = NULL;
    return new_env;
}

void get_setenv(int *already_execut, shell_t *my_shell)
{
    int i = my_tablen(my_shell->command);

    if (my_strcmp(my_shell->command[0], "setenv") == 0 && i <= 3) {
        if (i == 1) {
            my_shell->command[0] = "env";
            return;
        }
        my_shell->env = get_new_env(my_shell->env, my_shell->command, i);
        *already_execut = 1;
    } else if (my_strcmp(my_shell->command[0], "setenv") == 0 && i > 3) {
        write(2, "setenv: Too many arguments.\n", 28);
        *already_execut = 1;
    } else {
        if (my_strcmp(my_shell->command[0], "setenv") == 0 && i == 1) {
            execut_cmd(my_shell);
            *already_execut = 1;
        }
    }
}
