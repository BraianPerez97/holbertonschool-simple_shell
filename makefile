all: main.c main.h
	gcc -g -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./hsh	
