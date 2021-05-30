/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mohamed-reda.ramdani
** File description:
** monster
*/

#include "struct.h"
#include <stdlib.h>

void monster(game_t *game)
{
    int rng = rand() % 3;
    if (rng == 0)
        sfSprite_move(game->scene[GAME].sprite[9].sprite, (sfVector2f){0, -10});
    if (rng == 1)
        sfSprite_move(game->scene[GAME].sprite[9].sprite, (sfVector2f){0, 10});
    if (rng == 2)
        sfSprite_move(game->scene[GAME].sprite[9].sprite, (sfVector2f){10, 0});
    if (rng == 3)
        sfSprite_move(game->scene[GAME].sprite[9].sprite, (sfVector2f){-10, 0});
}