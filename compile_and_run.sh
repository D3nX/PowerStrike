#!/bin/bash
rm a.out
gcc *.c lib/*.c -I./include -g3 -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window
# gcc -W -Wextra -Wall -Werror main.c my_putchar.c delivery/*.c -L. -lmy
./a.out
