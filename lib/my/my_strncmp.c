/*
** EPITECH PROJECT, 2020
** 0
** File description:
** 0
*/

int  my_strncmp(char  const *s1 , char  const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && i <= n) {
        i++;
    }
    if (s1[i] < s2[i]) {
        return (-1);
    }
    if (s1[i] > s2[i]) {
        return (1);
    }
    if (s1[1] == '\0' && s2[i] == '\0' || i == n) {
        return (0);
    }
}
