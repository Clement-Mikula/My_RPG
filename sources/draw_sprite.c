/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** draw_sprite
*/

#include <stdio.h>

#include "struct.h"
#include "conf.h"

static void inventory_check(game_t *game)
{
    const sfView *view = NULL;
    sfVector2f middle = {0, 0};

    if (game->inventory == 1) {
        for (int i = 0; i <= game->scene[INVENTORY].nb_sprite - 1; ++i) {
            view = sfRenderWindow_getView(game->window);
            middle = sfView_getCenter(view);
            middle.x -= 150;
            middle.y += 250;
            sfSprite_setPosition(game->scene[INVENTORY].sprite[i].sprite,
                middle);
            sfRenderWindow_drawSprite(game->window,
                game->scene[INVENTORY].sprite[i].sprite, NULL);
        }
    }
}

static void dialogue_check(game_t *game, char const *path)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    const sfView *view = NULL;
    sfVector2f middle = {0, 0};

    if (game->dialogue == 1) {
        sfSprite_setTexture(sprite, texture, sfFalse);
        view = sfRenderWindow_getView(game->window);
        middle = sfView_getCenter(view);
        middle.x -= 250;
        middle.y += 250;
        sfSprite_setScale(sprite, (sfVector2f){0.5, 0.5});
        sfSprite_setPosition(sprite, middle);
        sfRenderWindow_drawSprite(game->window, sprite, NULL);
    }
}

void draw_sprite(game_t *game)
{
    int i = 0;

    if (game->current_scene != EXIT) {
        while (i <= game->scene[game->current_scene].nb_sprite - 1) {
            sfRenderWindow_drawSprite(game->window,
                game->scene[game->current_scene].sprite[i].sprite, NULL);
            ++i;
        }
        inventory_check(game);
        dialogue_check(game, "game_assets/dialogue_box.png");
        if (game->current_scene == GAME)
            sfRenderWindow_drawSprite(game->window,
                game->main_char.sprite, NULL);
    }
}