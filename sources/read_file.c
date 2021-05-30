/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** read_file
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char *read_file(char *filepath)
{
    struct stat stot;
    int fd = open(filepath, O_RDONLY);
    char *str = NULL;

    stat(filepath, &stot);
    str = malloc(sizeof(char) * stot.st_size + 1);
    if (str == NULL)
        return (NULL);
    read(fd, str, stot.st_size);
    str[stot.st_size] = '\0';
    return (str);
}