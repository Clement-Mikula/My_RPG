/*
** EPITECH PROJECT, 2021
** my_rpg_backup weird
** File description:
** menu_buttons
*/

#include "struct.h"

static void button1_menu_pressed(game_t *game)
{
    sfFloatRect button1 =
        sfSprite_getGlobalBounds(game->scene[MENU].sprite[1].sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    if (mouse_pos.y >= button1.top &&
        mouse_pos.y <= button1.top + button1.height &&
        mouse_pos.x >= button1.left &&
        mouse_pos.x <= button1.left + button1.width) {
        sfSprite_setTexture(game->scene[MENU].sprite[1].sprite,
            sfTexture_createFromFile("menu_assets/play_mouse.png", NULL), 1);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfSprite_setTexture(game->scene[MENU].sprite[1].sprite,
                sfTexture_createFromFile("menu_assets/play_click.png",
                    NULL), 1);
            game->current_scene = GAME;
        }
    } else
        sfSprite_setTexture(game->scene[MENU].sprite[1].sprite,
            sfTexture_createFromFile("menu_assets/play.png", NULL), 0);
}

static void button2_menu_pressed(game_t *game)
{
    sfFloatRect button1 =
        sfSprite_getGlobalBounds(game->scene[MENU].sprite[2].sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    if (mouse_pos.y >= button1.top &&
        mouse_pos.y <= button1.top + button1.height &&
        mouse_pos.x >= button1.left &&
        mouse_pos.x <= button1.left + button1.width) {
        sfSprite_setTexture(game->scene[MENU].sprite[2].sprite,
            sfTexture_createFromFile("menu_assets/options_mouse.png", NULL), 1);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfSprite_setTexture(game->scene[MENU].sprite[2].sprite,
                sfTexture_createFromFile("menu_assets/options_click.png",
                    NULL), 1);
            game->current_scene = OPTION;
        }
    } else
        sfSprite_setTexture(game->scene[MENU].sprite[2].sprite,
            sfTexture_createFromFile("menu_assets/options.png", NULL), 0);
}

static void button3_menu_pressed(game_t *game)
{
    sfFloatRect button1 =
        sfSprite_getGlobalBounds(game->scene[MENU].sprite[3].sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    if (mouse_pos.y >= button1.top &&
        mouse_pos.y <= button1.top + button1.height &&
        mouse_pos.x >= button1.left &&
        mouse_pos.x <= button1.left + button1.width) {
        sfSprite_setTexture(game->scene[MENU].sprite[3].sprite,
            sfTexture_createFromFile("menu_assets/quit_mouse.png", NULL), 1);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfSprite_setTexture(game->scene[MENU].sprite[3].sprite,
                sfTexture_createFromFile("menu_assets/quit_click.png",
                    NULL), 1);
            game->current_scene = EXIT;
        }
    } else
        sfSprite_setTexture(game->scene[MENU].sprite[3].sprite,
            sfTexture_createFromFile("menu_assets/quit.png", NULL), 0);
}

void menu_buttons(game_t *game)
{
    if (game->current_scene == MENU) {
        button1_menu_pressed(game);
        button2_menu_pressed(game);
        button3_menu_pressed(game);
    }
}