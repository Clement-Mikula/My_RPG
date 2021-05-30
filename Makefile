##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC			=	gcc

SRC			=	sources/main.c	\
				sources/conf.c	\
				sources/game_loop.c	\
				sources/read_file.c	\
				sources/draw_sprite.c	\
				sources/fill_struct.c	\
				sources/init_window.c	\
				sources/poll_event.c	\
				sources/count_lines.c	\
				sources/free_all.c	\
				sources/option_menu.c	\
				sources/menu_buttons.c	\
				sources/player.c	\
				sources/error_handling.c\
				sources/move_player.c	\
				sources/intro.c	\
				sources/monster.c	\

OBJ			=	$(SRC:.c=.o)

LDLIBS		=	-lmy

LDFLAGS		=	-L lib/my -l csfml-system -l csfml-window -l csfml-graphics -l csfml-audio -l csfml-network\

CPPFLAGS	=	-I ./include/

CFLAGS		=	-Wall -Wextra

NAME		=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) $(OBJ) -o $(NAME) $(LDLIBS) $(LDFLAGS) $(CPPFLAGS)

debug:	CFLAGS += -g
debug:	re

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
