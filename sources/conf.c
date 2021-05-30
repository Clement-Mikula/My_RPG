/*
** EPITECH PROJECT, 2021
** 0
** File description:
** 0
*/

#include <stdlib.h>

#include "my.h"
#include "struct.h"
#include "conf.h"

void conf(char *filepath, scene_t *scene)
{
    char *str = read_file(filepath);
    char **tab = my_str_to_word_array(str, '\n');
    char **page = NULL;

    scene->nb_sprite = count_lines(tab);
    scene->sprite = malloc(sizeof(sprite_t) * scene->nb_sprite);
    for (int i = 1; i <= scene->nb_sprite; i++) {
        page = my_str_to_word_array(tab[i], ' ');
        fill_struct(page, &(scene->sprite)[i - 1]);
    }
}