/*
** EPITECH PROJECT, 2020
** 0
** File description:
** 0
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest , char  const *src , int n)
{
    int i = 0;

    if (my_strlen(src)-1 < n)
    {
        dest[i];
        return dest;
    }
    while (i < n)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
