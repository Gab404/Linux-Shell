/*
** EPITECH PROJECT, 2022
** get_all_folder.c
** File description:
** get_all_folder
*/
#include <string.h>
#include "minishell.h"

void get_all_folder(char **env, shell_t *my_shell)
{
    char *path = get_path(env);
    char *reset_path = malloc(sizeof(char) * (my_strlen(path) + 1));
    int nb_folder = real_get_nb_word(path, ':');
    char *second_path = path;

    my_shell->all_folder = malloc(sizeof(char *) * (nb_folder + 1));
    reset_path[my_strlen(path)] = '\0';
    my_strcpy(reset_path, path);
    path += 5;
    second_path += 5;
    for (int i = 0; i < nb_folder; i++, path = second_path) {
        strtok(path, ":");
        second_path += my_strlen(path) + 1;
        my_shell->all_folder[i] = malloc(sizeof(char) * (my_strlen(path) + 1));
        my_shell->all_folder[i] = path;
        my_shell->all_folder[i][my_strlen(path)] = '\0';
    }
    my_shell->all_folder[nb_folder] = NULL;
    reset_good_path(reset_path, my_shell->env);
}