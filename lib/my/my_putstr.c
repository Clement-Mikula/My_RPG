/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** a
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int j;

    j = 0;
    while (str[j] != '\0')
    {
        my_putchar(str[j]);
        j++;
    }
}
