/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** 0
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int carry = 0;

    if (nb <= -2147483648)
        return (0);
    if (nb >= 2147483648)
        return (0);
    if (nb < 0) {
        my_putchar ('-');
        nb = -nb;
    }
    if (nb <= 9) {
        my_putchar(nb + '0');
    }
    if (nb >= 10) {
        carry = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(carry + '0');
    }
}
