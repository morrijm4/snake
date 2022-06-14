CC = gcc

prog = snake

all:
	@$(CC) main.c -o $(prog) -Wall $(wildcard src/*.c) $(wildcard utils/*.c) -I include -L lib -l SDL2-2.0.0

run:
	@$(CC) main.c -o $(prog) -Wall $(wildcard src/*.c) $(wildcard utils/*.c) -I include -L lib -l SDL2-2.0.0
	@./$(prog)