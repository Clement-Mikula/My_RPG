/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** loop
*/

#include "struct.h"
#include "conf.h"

static void refresh_character(character_t *character)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds = 0;
    int width = 72;
    static int tempo = 0;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if ((seconds >= 1 / 60) && (tempo == 10)) {
        tempo = 0;
        if (character->rect.left >= (character->nb_frames - 1) * width)
            character->rect.left = 0;
        sfSprite_setTextureRect(character->sprite, character->rect);
        sfClock_restart(clock);
        character->rect.left += width;
    }
    tempo += 1;
}

static void init_char(game_t *game)
{
    int height = 78;
    int width = 72;

    game->main_char.texture = sfTexture_createFromFile("zelda.png", NULL);
    game->main_char.sprite = sfSprite_create();
    game->main_char.rect = (sfIntRect){0, 0, width, height};
    sfSprite_setTexture(game->main_char.sprite,
        game->main_char.texture, sfFalse);
    sfSprite_setTextureRect(game->main_char.sprite, game->main_char.rect);
    game->main_char.nb_frames = 3;
}

static void init_scenes(game_t *game)
{
    conf("conf/game.conf", &(game->scene[0]));
    conf("conf/menu.conf", &(game->scene[1]));
    conf("conf/pause.conf", &(game->scene[2]));
    conf("conf/inventory.conf", &(game->scene[3]));
    conf("conf/intro.conf", &(game->scene[4]));
}

void game_loop(game_t *game)
{
    init_scenes(game);
    game->window = init_window("My_RPG");
    init_char(game);
    game->dialogue = 0;
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        poll_event(game);
        draw_sprite(game);
        refresh_character(&(game->main_char));
        player(game);
        monster(game);
        sfRenderWindow_display(game->window);
    }
}