/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** poll_event
*/

#include "my.h"
#include "struct.h"
#include "conf.h"

static void game_inventory(game_t *game)
{
    if (game->current_scene == GAME &&
    game->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyI)) {
        if (game->inventory == 0)
            game->inventory = 1;
        else if (game->inventory == 1)
            game->inventory = 0;
    }
}

static void intro_interaction(game_t *game)
{
    if (game->current_scene == INTRO) {
        sfVector2f vec = {
            vec.x = 0,
            vec.y = 1
        };
        sfSprite_move(game->scene[INTRO].sprite[0].sprite, vec);
        if (game->event.type == sfEvtKeyPressed)
            game->current_scene = MENU;
    }
}

static int is_a_sprite_collision(sfSprite *sprite, game_t *game)
{
    sfFloatRect button1 = sfSprite_getGlobalBounds(sprite);
    sfVector2f character_pos = sfSprite_getPosition(game->main_char.sprite);

    button1.height += 50;
    button1.top += -50;
    button1.width += 50;
    button1.left += -50;
    if (character_pos.y >= button1.top &&
        character_pos.y <= button1.top + button1.height &&
        character_pos.x >= button1.left &&
        character_pos.x <= button1.left + button1.width)
            return 1;
    return 0;
}

static int check_char_collision(game_t *game)
{
    int collision = 0;

    if (is_a_sprite_collision(game->scene[GAME].sprite[8].sprite, game) == 1)
        collision += 1;
    if (collision > 0)
        return 1;
    return 0;
}

void poll_event(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
        if (game->event.type == sfEvtClosed || game->current_scene == EXIT)
            sfRenderWindow_close(game->window);
        intro_interaction(game);
        game_inventory(game);
        option_menu(game);
        game->dialogue = check_char_collision(game);
        menu_buttons(game);
    }
}