/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** fill_struct
*/

#include <unistd.h>

#include "struct.h"
#include "my.h"

void fill_struct(char **page, sprite_t *sprite)
{
    sfVector2f position = {
        position.x = my_getnbr(page[3]),
        position.y = my_getnbr(page[4])
    };
    sfVector2f scale = {
        scale.x = my_getnbr(page[5]),
        scale.y = my_getnbr(page[5])
    };

    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(page[0], NULL);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setScale(sprite->sprite, scale);
    sfSprite_setPosition(sprite->sprite, position);
}