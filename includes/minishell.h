/*
** EPITECH PROJECT, 2021
** minishell.h
** File description:
** minishell
*/

#ifndef MINISHELL_H
    #define MINISHELL_H
    #include <signal.h>
    #include <sys/wait.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <stdbool.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <stdio.h>
    #include "../lib_printf/includes/bsprintf.h"
    #include "shell_struct.h"

int handle_input(char *buffer);
char **reset_good_path(char *reset_path, char **env);
void do_cmd(char *buffer, shell_t *my_shell);
char *get_path(char **env);
void get_all_folder(char **env, shell_t *my_shell);
void execut_cmd(shell_t *my_shell);
bool find_pipe(char **command);
void display_error(char *str);
void get_cd(int *executed_cmd, shell_t *my_shell);
int my_tablen(char **tab);
void handle_segfault(int status);
void get_all_folder(char **env, shell_t *my_shell);
void get_setenv(int *already_execut, shell_t *my_shell);
char *get_good_path(char **all_folder, char *command);
int my_show_word_array(char **tab);
int gest_error_file(char *path);
void execut_file(char *buffer, shell_t *my_shell);
void handle_buffer(char *buffer, int nb_word, shell_t *my_shell);
char *fill_path(char *path, char *command, char **env);
int get_nb_word(char *buffer, char d1, char d2);
int real_get_nb_word(char *buffer, char d1);
int my_strcmp(char *s1, char *s2);
void get_exit(char *buffer);
char *my_strcpy(char *dest, char *src);
void get_unsetenv(shell_t *my_shell, int *already_execut);
void execute_with_pipe(shell_t *my_shell);
void get_all_command(int nb_action, shell_t *my_shell, char *buffer);

#endif
