/*
** EPITECH PROJECT, 2020
** a
** File description:
** a
*/

void my_putchar(char c);

int my_strlen(char const *str);

int my_put_nbr(int nb);

int my_getnbr(char *str)
{
    int jsp = 1;
    int res = 0;
    int tmp = 0, i = 0, j = 0;

    for (; str[i] == '-'; i++)
        jsp++;
    if (i % 2 == 1)
        j = 1;

    for (; i < my_strlen(str); i++)
        if ('0' <= str[i] && str[i] <= '9') {
            tmp = (str[i] - '0');
            for (int k = 0; k < (my_strlen(str) - jsp); k++)
                tmp = tmp * 10;
            res += tmp;
            jsp++;
        }
    if (j == 1)
        res = res * (-1);
    return res;
}
