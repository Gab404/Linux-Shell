/*
** EPITECH PROJECT, 2022
** get_cd.c
** File description:
** get_cd
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "minishell.h"

int check_is_not_same_word(char c1, char c2, int same_word)
{
    if (c1 != c2)
        return 1;
    return same_word;
}

char *get_env_var(char **env, char *var)
{
    int same_word = 0;

    for (int i = 0; env[i] != NULL; i++) {
        for (int j = 0; var[j] != '\0' && env[i][j] != 0; j++)
            same_word = check_is_not_same_word(var[j], env[i][j], same_word);
        if (same_word == 0)
            return env[i] + my_strlen(var) + 1;
        same_word = 0;
    }
    return NULL;
}

void fct_cd(shell_t *my_shell)
{
    int exist = access(my_shell->command[1], F_OK);
    struct stat sb;

    if (my_shell->command[1][0] == '-' && my_shell->command[1][1] == '\0') {
        chdir(my_shell->last_path);
        return;
    }
    if (exist == -1) {
        display_error(my_shell->command[1]);
        display_error(": No such file or directory.\n");
    } else {
        stat(my_shell->command[1], &sb);
        if (S_ISREG(sb.st_mode)) {
            display_error(my_shell->command[1]);
            display_error(": Not a directory.\n");
        } else
            chdir(my_shell->command[1]);
    }
    if (my_shell->set_new_last_path % 2 == 0)
        getcwd(my_shell->last_path, 200);
}

void cd_alone(shell_t *my_shell)
{
    if (my_strcmp(my_shell->command[0], "cd") == 0) {
        chdir(get_env_var(my_shell->env, "HOME"));
    }
    if (my_shell->set_new_last_path % 2 == 0)
        getcwd(my_shell->last_path, 200);
    return;
}

void get_cd(int *executed_cmd, shell_t *my_shell)
{
    int nb_arg = my_tablen(my_shell->command);

    if (FIRST || (SEC && THIRD)) {
        cd_alone(my_shell);
        *executed_cmd = 1;
        my_shell->set_new_last_path++;
        return;
    }
    if (my_strcmp(my_shell->command[0], "cd") == 0 && QUATRO) {
        *executed_cmd = 1;
        fct_cd(my_shell);
        my_shell->set_new_last_path++;
    } else if (my_strcmp(my_shell->command[0], "cd") == 0 && nb_arg >= 3) {
        display_error("cd: Too many arguments.\n");
        *executed_cmd = 1;
    }
}