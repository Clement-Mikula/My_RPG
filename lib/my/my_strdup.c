/*
** EPITECH PROJECT, 2020
** 0
** File description:
** 0
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char  const *src)
{
    char *str;
    int i;
    int length = my_strlen(src);


    str = malloc (sizeof(char) * length);
    i = 0;
    while (i < length)
    {
        str[i] = src[i];
        i = i + 1;
    }
    str[i] = '\0';
    return (str);
    free (str);
}
