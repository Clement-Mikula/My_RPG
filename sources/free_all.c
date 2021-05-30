/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** free_all
*/

#include <stdlib.h>

#include "struct.h"

static void free_scene(game_t *game)
{
    for (int j = 0; j < game->nb_scene; j++) {
        for (int i = 0; i < game->scene[j].nb_sprite; i++) {
            sfSprite_destroy(game->scene[j].sprite[i].sprite);
            sfTexture_destroy(game->scene[j].sprite[i].texture);
        }
    }
    free(game->scene);
}

static void free_character(game_t * game)
{
    sfSprite_destroy(game->main_char.sprite);
    sfTexture_destroy(game->main_char.texture);
}

void free_all(game_t *game)
{
    free_scene(game);
    free_character(game);
    sfRenderWindow_destroy(game->window);
}