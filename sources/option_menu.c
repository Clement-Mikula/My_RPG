/*
** EPITECH PROJECT, 2021
** my_rpg_backup weird
** File description:
** option
*/

#include "struct.h"

static void button1_option_pressed(game_t *game)
{
    sfFloatRect button1 =
        sfSprite_getGlobalBounds(game->scene[OPTION].sprite[1].sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    if (mouse_pos.y >= button1.top &&
        mouse_pos.y <= button1.top + button1.height &&
        mouse_pos.x >= button1.left &&
        mouse_pos.x <= button1.left + button1.width) {
        sfSprite_setTexture(game->scene[OPTION].sprite[1].sprite,
            sfTexture_createFromFile("pause_assets/back_menu_mouse.png",
                NULL), 1);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfSprite_setTexture(game->scene[OPTION].sprite[1].sprite,
                sfTexture_createFromFile("pause_assets/back_menu_click.png",
                    NULL), 1);
            game->current_scene = MENU;
        }
    } else
        sfSprite_setTexture(game->scene[OPTION].sprite[1].sprite,
            sfTexture_createFromFile("pause_assets/back_menu.png", NULL), 0);
}

static void button2_option_pressed(game_t *game)
{
    sfFloatRect button1 =
        sfSprite_getGlobalBounds(game->scene[OPTION].sprite[2].sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    if (mouse_pos.y >= button1.top &&
        mouse_pos.y <= button1.top + button1.height &&
        mouse_pos.x >= button1.left &&
        mouse_pos.x <= button1.left + button1.width) {
        sfSprite_setTexture(game->scene[OPTION].sprite[2].sprite,
            sfTexture_createFromFile("pause_assets/quit_mouse.png", NULL), 1);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfSprite_setTexture(game->scene[OPTION].sprite[2].sprite,
                sfTexture_createFromFile("pause_assets/quit_click.png",
                    NULL), 1);
            game->current_scene = EXIT;
        }
    } else
        sfSprite_setTexture(game->scene[OPTION].sprite[2].sprite,
            sfTexture_createFromFile("pause_assets/quit.png", NULL), 0);
}

static void option_hitbox(game_t *game)
{
    button1_option_pressed(game);
    button2_option_pressed(game);
}

void option_menu(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (game->current_scene == GAME)
            game->current_scene = OPTION;
        else if (game->current_scene == OPTION)
            game->current_scene = GAME;
    } if (game->current_scene == OPTION)
        option_hitbox(game);
}
