/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mohamed-reda.ramdani
** File description:
** intro
*/

#include <stdlib.h>

#include "struct.h"

static void intro_interaction(game_t *game, sfSprite *sprite, float x, float y)
{
    sfVector2f vec = {x, y};
    sfVector2f pos = {10000, 10000};
    float angle = sfSprite_getRotation(sprite);
    float rng = rand() % 10;
    sfColor color = sfSprite_getColor(sprite);

    if (game->current_scene == MENU) {
        angle += 1;
        rng /= 10;
        sfSprite_setRotation(sprite, angle);
        sfSprite_move(sprite, vec);
        color.a -= 1;
        if (color.a == 0) {
            sfSprite_setPosition(sprite, pos);
        }
    }
}

void intro_move(game_t *game)
{
    intro_interaction(game, game->scene[MENU].sprite[5].sprite, 0, 1);
    intro_interaction(game, game->scene[MENU].sprite[6].sprite, 1, 0);
    intro_interaction(game, game->scene[MENU].sprite[7].sprite, 2, 0);
    intro_interaction(game, game->scene[MENU].sprite[8].sprite, 0, 2);
}
