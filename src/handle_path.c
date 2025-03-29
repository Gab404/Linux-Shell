/*
** EPITECH PROJECT, 2022
** handle_path.c
** File description:
** handle_path
*/

#include <string.h>
#include "minishell.h"

char *get_path(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T')
            return env[i];
    }
    return NULL;
}

char **reset_good_path(char *reset_path, char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T') {
            env[i] = malloc(sizeof(char) * (my_strlen(reset_path) + 1));
            my_strcpy(env[i], reset_path);
            env[i][my_strlen(reset_path)] = '\0';
            return env;
        }
    }
    return env;
}

char *get_good_path(char **all_folder, char *command)
{
    char *path;
    int len;
    int i_cmd = 0;

    for (int i = 0; all_folder[i] != NULL; i++, path = NULL) {
        len = my_strlen(all_folder[i]) + my_strlen(command) + 1;
        path = malloc(sizeof(char) * (len + 1));
        my_strcpy(path, all_folder[i]);
        path[my_strlen(all_folder[i])] = '/';
        for (int j = my_strlen(all_folder[i]) + 1; FIVO; j++, i_cmd++)
            path[j] = command[i_cmd];
        i_cmd = 0;
        path[len] = '\0';
        if (access(path, F_OK) == 0)
            return path;
    }
    display_error(command);
    display_error(": Command not found.\n");
    return NULL;
}

void get_all_command(int nb_action, shell_t *my_shell, char *buffer)
{
    int tmp_len;
    char *tmp_str;

    my_shell->nb_command = nb_action;
    my_shell->all_action = malloc(sizeof(char *) * (nb_action + 1));
    for (int i = 0; i < nb_action; i++, buffer = NULL) {
        tmp_str = strtok(buffer, ";");
        if (tmp_str == NULL) {
            break;
        }
        tmp_len = my_strlen(tmp_str);
        my_shell->all_action[i] = malloc(sizeof(char) * (tmp_len + 1));
        my_strcpy(my_shell->all_action[i], tmp_str);
        my_shell->all_action[i][tmp_len] = '\0';
    }
    my_shell->all_action[nb_action] = NULL;

    return;
}

void handle_buffer(char *buffer, int nb_word, shell_t *my_shell)
{
    char *tmp_str;
    int tmp_len;

    my_shell->command = malloc(sizeof(char *) * (nb_word + 1));
    for (int i = 0; i != nb_word; i++, buffer = NULL) {
        tmp_str = strtok(buffer, "; \t");
        if (tmp_str == NULL) {
            my_shell->command[nb_word] = NULL;
            return;
        }
        tmp_len = my_strlen(tmp_str);
        my_shell->command[i] = malloc(sizeof(char) * (tmp_len + 1));
        my_strcpy(my_shell->command[i], tmp_str);
        my_shell->command[i][tmp_len] = '\0';
    }
    my_shell->command[nb_word] = NULL;
    return;
}
