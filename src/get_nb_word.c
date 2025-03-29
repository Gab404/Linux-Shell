/*
** EPITECH PROJECT, 2021
** get_nb_word.c
** File description:
** get_nb_word
*/

#include "minishell.h"

int get_nb_word(char *buffer, char d1, char d2)
{
    int nb_word = 1;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == d1 || buffer[i] == d2)
            nb_word++;
    }
    return nb_word;
}

int handle_input(char *buffer)
{
    int res_read = 0;

    while (res_read == 0) {
        res_read = read(0, buffer, 300);
        if (res_read == 0)
            exit(0);
        if (res_read == 1 && buffer[0] == '\n')
            return 0;
    }
    return res_read;
}
