/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** count_lines
*/

#include <stdlib.h>
#include <stdio.h>

int count_lines(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    i -= 1;
    return (i);
}