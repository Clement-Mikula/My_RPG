/*
** EPITECH PROJECT, 2020
** 0
** File description:
** 0
*/

#include <stdlib.h>
#include <stdio.h>

int count_parse(char *str, char pars)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == pars)
            count++;
    }
    return count + 1;
}

int count_rows(char *str, char pars)
{
    int i = 0;
    for (; str[i] != pars && str[i] != '\0'; i++);
    return i;
}

char **mem_tab(char *str, int len, char pars)
{
    char **tab = malloc(sizeof(char *) * (len + 1));
    int rows = count_rows(str, pars);

    for (int i = 0; i < len; i++) {
        tab[i] = malloc(sizeof(char) * (rows + 1));
        if (str[rows] != '\0')
            str += rows + 1;
        tab[i][rows] = '\0';
        rows = count_rows(str, pars);
    }
    tab[len] = NULL;
    return tab;
}

char **my_str_to_word_array(char *str, char pars)
{
    int len = count_parse(str, pars);
    char **tab = mem_tab(str, len, pars);

    int k = 0;
    for (int i = 0; i < len; i++, k++)
    {
        for (int j = 0;str[k] != pars && str[k] != '\0'; j++, k++)
            tab[i][j] = str[k];
    }
    return tab;
}