CC=gcc
CFLAGS = -I/usr/local/include -I. -L/usr/local/lib -lraylib -lm -lpthread -ldl -lrt -lX11

all: run

run: raylib_game.c 
		$(CC) raylib_game.c -o A-STAR $(CFLAGS)