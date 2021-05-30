/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_window
*/

#include "struct.h"

sfRenderWindow *init_window(char const *title)
{
    unsigned int frame_rate = 60;
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    sfUint32 style = sfTitlebar | sfClose | sfResize;

    window = sfRenderWindow_create(mode, title, style, NULL);
    sfRenderWindow_setFramerateLimit(window, frame_rate);
    return (window);
}