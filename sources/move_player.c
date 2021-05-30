/*
** EPITECH PROJECT, 2021
** MY_RPG
** File description:
** move_player
*/

#include "conf.h"
#include "struct.h"
#include "event.h"

static int is_a_sprite_collision(sfSprite *sprite, game_t *game)
{
    sfFloatRect main_char = sfSprite_getGlobalBounds(game->main_char.sprite);
    sfFloatRect button1 = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&button1, main_char.left, main_char.top))
        return 1;
    return 0;
}

static int check_char_collision(game_t *game)
{
    int collision = 0;

    for (int i = 1; i < game->scene[GAME].nb_sprite - 1; ++i) {
        if (is_a_sprite_collision(game->scene[GAME].sprite[i].sprite, game) == 1)
            ++collision;
    }
    if (collision > 0)
        return 1;
    return 0;
}

static int player_movement(game_t *game)
{
    int i = 0;
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds = 0;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds >= 30 / 60) {
        if (sfKeyboard_isKeyPressed(sfKeyZ)) {
            game->main_char.rect.top = BACK_WALK_POS;
            game->main_char.nb_frames = WALK_FRAMES;
            if (check_char_collision(game) == 0)
                sfSprite_move(game->main_char.sprite, (sfVector2f){0, -10});
            else
                sfSprite_move(game->main_char.sprite, (sfVector2f){0, 50});
            ++i;
        } if (sfKeyboard_isKeyPressed(sfKeyS)) {
            game->main_char.rect.top = FRONT_WALK_POS;
            game->main_char.nb_frames = WALK_FRAMES;
            if (check_char_collision(game) == 0)
                sfSprite_move(game->main_char.sprite, (sfVector2f){0, 10});
            else
                sfSprite_move(game->main_char.sprite, (sfVector2f){0, -50});
            ++i;
        }
        if (sfKeyboard_isKeyPressed(sfKeyQ)) {
            game->main_char.rect.top = LEFT_WALK_POS;
            game->main_char.nb_frames = WALK_FRAMES;
            if (check_char_collision(game) == 0)
                sfSprite_move(game->main_char.sprite, (sfVector2f){-10, 0});
            else
                sfSprite_move(game->main_char.sprite, (sfVector2f){50, 0});
            ++i;
        } if (sfKeyboard_isKeyPressed(sfKeyD)) {
            game->main_char.rect.top = RIGHT_WALK_POS;
            game->main_char.nb_frames = WALK_FRAMES;
            if (check_char_collision(game) == 0)
                sfSprite_move(game->main_char.sprite, (sfVector2f){10, 0});
            else
                sfSprite_move(game->main_char.sprite, (sfVector2f){-50, 0});
            ++i;
        }
    } if (i > 0)
        return i;
    return 0;
}

void player_move(game_t *game)
{
    if (player_movement(game) == 0) {
        game->main_char.rect.top = FRONT_IDLE_POS;
        game->main_char.nb_frames = IDLE_FRAMES;
    }
}