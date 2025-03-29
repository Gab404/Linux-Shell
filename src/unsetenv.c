/*
** EPITECH PROJECT, 2022
** unsetenv.c
** File description:
** unsetenv
*/

#include "minishell.h"

char **resize_env(char **env, int line)
{
    char **new_env;
    int size_env = 0;

    while (env[size_env] != NULL)
        size_env++;
    new_env = malloc(sizeof(char *) * (size_env + 1));
    for (int i = 0; env[i + 1] != NULL; i++) {
        if (i < line) {
            new_env[i] = malloc(sizeof(char) * my_strlen(env[i]));
            my_strcpy(new_env[i], env[i]);
        } else {
            new_env[i] = malloc(sizeof(char) * my_strlen(env[i + 1]));
            my_strcpy(new_env[i], env[i + 1]);
        }
    }
    new_env[size_env] = NULL;
    return new_env;
}

char **remove_var_env(char **command, char **env)
{
    char *name_var = command[1];
    char *tmp_var;
    int j = 0;

    for (int i = 0; env[i] != NULL; i++) {
        while (env[i][j] != '=')
            j++;
        tmp_var = malloc(sizeof(char) * my_strlen(env[i]));
        my_strcpy(tmp_var, env[i]);
        tmp_var[j] = '\0';
        if (my_strcmp(tmp_var, name_var) == 0) {
            env = resize_env(env, i);
            return env;
        }
        tmp_var[0] = '\0';
        j = 0;
    }
    return env;
}

void get_unsetenv(shell_t *my_shell, int *already_execut)
{
    if (my_strcmp(my_shell->command[0], "unsetenv") == 0 && SIXIO) {
        display_error("unsetenv: Too few arguments.\n");
        *already_execut = 1;
    } else if (my_strcmp(my_shell->command[0], "unsetenv") == 0) {
        my_shell->env = remove_var_env(my_shell->command, my_shell->env);
        *already_execut = 1;
    }
    return;
}