#include <stdio.h>

#define BOARD_LENGTH 7
#define BOARD_HEIGHT 6

void create_board(char board[BOARD_LENGTH][BOARD_HEIGHT]) {
	for (int x = 0; x < BOARD_LENGTH; x++) {
		for (int y = 0; y < BOARD_HEIGHT; y++) {
			board[x][y] = ' ';
		}
	}
}

void print_board(char board[BOARD_LENGTH][BOARD_HEIGHT]) {
	for (int x = BOARD_HEIGHT-1; x > 0; x--) {
		for (int y = 0; y < BOARD_LENGTH; y++) {
			printf("|%c", board[x][y]);
		}
		printf("|\n");
	}
}

int main(void) {
	char board[BOARD_LENGTH][BOARD_HEIGHT];
	create_board(board);
	print_board(board);
}