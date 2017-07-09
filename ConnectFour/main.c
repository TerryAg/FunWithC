#include <stdio.h>

#define BOARD_LENGTH 7
#define BOARD_HEIGHT 6

void create_board(char board[BOARD_LENGTH][BOARD_HEIGHT]) {
	for (int x = 0; x <= BOARD_LENGTH; x++) {
		for (int y = 0; y <= BOARD_HEIGHT; y++) {
			board[x][y] = ' ';
		}
	}
}

void print_board(char board[BOARD_LENGTH][BOARD_HEIGHT]) {
	for (int x = BOARD_HEIGHT; x >= 0; x--) {
		for (int y = 0; y < BOARD_LENGTH; y++) {
			printf("|%c", board[x][y]);
		}
		printf("|\n");
	}
	for (int y = 1; y <= BOARD_LENGTH; y++) {
		printf(" %d", y);
	}
	printf("\n");
}

void turn(char board[BOARD_LENGTH][BOARD_HEIGHT]) {

}
int main(void) {
	char board[BOARD_LENGTH][BOARD_HEIGHT];
	create_board(board);
	print_board(board);

}