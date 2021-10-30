##
## DENITEK PROJECT, 2021
## Power strike
## File description:
## Compile PowerStrike lib & example
##

SRC =   ./main.c \
		./gamestate.c \
		./menustate.c \
		./lib/rendertexture.c

OBJ = $(SRC:.c=.o)

CFLAGS += -I./include # -W -Wextra -Wall -Werror

NAME = game

$(NAME): $(OBJ)
#	make -C lib/my
	gcc -o $(NAME) $(OBJ) -I./include -L./lib -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window 

all:	 $(NAME)

clean:
#	make clean -C lib/my
	rm -f $(OBJ)

fclean: clean
#	make clean -C lib/my
	rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
