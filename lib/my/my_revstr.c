/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** a
*/

#include <stdio.h>
#include <string.h>

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int n = my_strlen(str) - 1;
    int ptr = 0;
    while (i < n) {
        ptr = str[i];
        str[i] = str[n];
        str[n] = ptr;
        i++;
        n++;
    }
    return (str);
}
