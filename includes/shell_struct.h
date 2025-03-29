/*
** EPITECH PROJECT, 2022
** shell_struct.h
** File description:
** shell_struct
*/

#ifndef SHELL_STRUCT_H
    #define SHELL_STRUCT_H
    #include <signal.h>
    #define FIRST (nb_arg == 1 && my_strcmp(my_shell->command[0], "cd") == 0)
    #define SEC nb_arg == 2 && my_strcmp(my_shell->command[0], "cd") == 0
    #define THIRD my_strcmp(my_shell->command[1], "~") == 0
    #define QUATRO (nb_arg < 3 && nb_arg != 1)
    #define FIVO j < my_strlen(all_folder[i]) + my_strlen(command) + 1
    #define SIXIO my_shell->command[1] == NULL

typedef struct shell_s {
    char **command;
    char **all_folder;
    char **env;
    int status;
    pid_t pid_father;
    int nb_command;
    char **all_action;
    char ***already_all_action;
    char *last_path;
    int set_new_last_path;
} shell_t;

#endif
