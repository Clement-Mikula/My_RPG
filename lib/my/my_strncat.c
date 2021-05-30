/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** a
*/

#include <stddef.h>

int my_strlen(char const *str);

char *my_strncat(char *dest , char const *src , int nb)
{
    size_t dest_len = my_strlen(dest);
    size_t i;

    for (i = 0 ; i < nb && src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    return dest;
}
