/*
** EPITECH PROJECT, 2022
** lib.c
** File description:
** lib
*/

#include "minishell.h"

int my_show_word_array(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_printf("%s\n", tab[i]);
        i++;
    }
    return 0;
}

int my_strcmp(char *s1, char *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return -1;
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return -1;
    }
    return 0;
}

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return dest;
}

int real_get_nb_word(char *buffer, char d1)
{
    int nb_word = 1;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == d1 && (i != 0 && d1 != ' '))
            nb_word++;
        else if (buffer[i] == d1 && i != 0)
            nb_word++;
    }
    return nb_word;
}

int my_tablen(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;

    return i;
}
