/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>

typedef struct sprite_s
{
    sfSprite *sprite;
    sfTexture *texture;
} sprite_t;

typedef struct scene_s
{
    int nb_sprite;
    sprite_t *sprite;
}scene_t;

typedef struct character_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    int speed;
    int nb_frames;
} character_t;

typedef struct game_s
{
    scene_t *scene;
    sfEvent event;
    int nb_scene;
    int current_scene;
    sfRenderWindow *window;
    int inventory;
    int dialogue;
    character_t main_char;
}game_t;

enum scene {
    EXIT = -1,
    GAME,
    MENU,
    OPTION,
    INVENTORY,
    INTRO
};

#endif /* !STRUCT_H_ */