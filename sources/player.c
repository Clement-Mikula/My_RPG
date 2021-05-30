/*
** EPITECH PROJECT, 2021
** my_rpg_backup weird
** File description:
** player
*/

#include "conf.h"
#include "struct.h"
#include "event.h"

static void player_camera(game_t *game)
{
    const sfView *view = NULL;
    sfVector2f vec = {0, 0};

    if (game->current_scene == GAME) {
        view = sfRenderWindow_getView(game->window);
        vec = sfSprite_getPosition(game->main_char.sprite);
        sfView_setCenter((sfView *)view, vec);
        sfRenderWindow_setView(game->window, view);
    } else
        sfRenderWindow_getDefaultView(game->window);
}

static void player_attack(game_t *game)
{
    sfSprite *sprite = NULL;
    sfTexture *texture = NULL;
    sfVector2f player_pos = {0, 0};

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sprite = sfSprite_create();
        texture = sfTexture_createFromFile("game_assets/master_sword.png", NULL);
        sfSprite_rotate(sprite, 45);
        sfSprite_setTexture(sprite, texture, 0);
        player_pos = sfSprite_getPosition(game->main_char.sprite);
        player_pos.x += 80;
        sfSprite_setPosition(sprite, player_pos);
        sfSprite_setScale(sprite, (sfVector2f){0.1, 0.1});
        sfRenderWindow_drawSprite(game->window, sprite, NULL);
        sfTexture_destroy(texture);
    }
}

void player(game_t *game)
{
    const sfView *view2 = NULL;

    if (game->current_scene == GAME) {
        player_camera(game);
        player_move(game);
        player_attack(game);
    } else {
        view2 = sfRenderWindow_getDefaultView(game->window);
        sfRenderWindow_setView(game->window, view2);
    }
}
