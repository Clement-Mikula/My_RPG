/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>

#include "struct.h"
#include "conf.h"

static int usage(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        write(1, "USAGE\n\t./my_rpg\n", 17);
        write(1, "DESCRIPTION\n\tThis is our Role Playing Game"
                ", an epitech project"
                " made by Math yeux and Clement the bot and Redouille and las"
                "t but not least Lait-eau\n\t"
                "The goal of this game is to kill Ganon without killing"
                " yourself and bring back the Master Sword"
                "\n\tGLHF, NOOB\n",
                257);
        return (EXIT_SUCCESS);
    }
    return (EXIT_FAILURE);
}

int main(int argc, char **argv, char **env)
{
    game_t game;

    if (usage(argc, argv) == EXIT_SUCCESS)
        return (EXIT_SUCCESS);
    if (error_handling(argc, env) == EXIT_FAILURE)
        return (84);
    game.current_scene = INTRO;
    game.nb_scene = 4;
    game.inventory = 0;
    game.scene = malloc(sizeof(scene_t) * (game.nb_scene + 1));
    game_loop(&game);
    free_all(&game);
    return 0;
}
