##
## EPITECH PROJECT, 2021
## Final stumper
## File description:
## Compile final stumper program
##

SRC =   ./main.c \
		./gamestate.c \
		./menustate.c \
		./lib/rendertexture.c

OBJ = $(SRC:.c=.o)

CFLAGS += -I./include -W -Wextra -Wall -Werror -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

NAME = game

$(NAME): $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) -I./include -L./lib

all:	 $(NAME)

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean: clean
	make clean -C lib/my
	rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
