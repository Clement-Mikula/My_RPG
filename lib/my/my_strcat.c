/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** a
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strcat(char *dest , char  const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)));
    size_t dest_len = my_strlen(dest);
    size_t i;

    my_strcpy(str, dest);
    for (i = 0 ; src[i] != '\0' ; i++)
        str[dest_len + i] = src[i];
    str[dest_len + i] = '\0';

    return str;
}