/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** conf
*/

#include "struct.h"

#ifndef CONF_H_
#define CONF_H_

void conf(char *filepath, scene_t *game);
void poll_event(game_t *game);
int count_lines(char **tab);
char *read_file(char *filepath);
void draw_sprite(game_t *game);
void fill_struct(char **page, sprite_t *sprite);
sfRenderWindow *init_window(char const *title);
void game_loop(game_t *game);
void free_all(game_t *game);
void init_game();
void option_menu(game_t *game);
void menu_buttons(game_t *game);
void player(game_t *game);
int error_handling(int ac, char **env);
void intro_move(game_t *game);
void player_move(game_t *game);
void monster(game_t *game);

#endif /* !CONF_H_ */
