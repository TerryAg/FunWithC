#include <stdio.h>
#include "tictactoe.h"

void create_board(char board[BOARD_SIZE][BOARD_SIZE]) {
	for (int x = 0; x < BOARD_SIZE; x++) {
		for (int y = 0; y < BOARD_SIZE; y++) {
			board[x][y] = x*BOARD_SIZE+y+1 + '0'; 
		}
	}
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
	for (int x = 1; x <= BOARD_SIZE*BOARD_SIZE; x++) {
		if (x % BOARD_SIZE == 0) {
			for (int y = 0; y < BOARD_SIZE; y++) {
				printf("|%c", board[(x/BOARD_SIZE) - 1][y]);
			}
			printf("|\n");
		}
	}
}