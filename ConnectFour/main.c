#include <stdio.h>
#include <stdlib.h>

#define BOARD_LENGTH 7
#define BOARD_HEIGHT 6
#define MAX_LINE 128

void create_board(char board[BOARD_LENGTH][BOARD_HEIGHT]) {
	for (int x = 0; x < BOARD_LENGTH; x++) {
		for (int y = 0; y < BOARD_HEIGHT; y++) {
			board[x][y] = ' ';
		}
	}
}

void print_board(char board[BOARD_LENGTH][BOARD_HEIGHT]) {
	for (int x = BOARD_HEIGHT-1; x >= 0; x--) {
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

int top_of_col(char board[BOARD_LENGTH][BOARD_HEIGHT], int column) {
	// Returns the top-most empty space of a column
	for (int x = BOARD_HEIGHT-1; x >= 0; x--) {
		if (board[x][column] == ' ') {
			return x;
		}
	}
	return -1; // full col. shouldn't happen
}

void turn(char board[BOARD_LENGTH][BOARD_HEIGHT], char pattern) {
	char input[MAX_LINE];
	char *end;
	int choice, num;
	printf("Player #: Pick a column. ");
	while (fgets(input, MAX_LINE, stdin) != '\0') {
		choice = strtol(input, &end, 10);
		if (end == input) {
			printf("That's not a number! ");
		} else if ((choice < 1) || (choice > BOARD_LENGTH)) {
			printf("That number is out of range! ");
		} else if (board[BOARD_HEIGHT-1][choice] != ' ') {
			printf("Column is full! ");
		} else {
			board[top_of_col(board, choice-1)][choice-1] = pattern;
			return;
		}

	}
}

int main(void) {
	char board[BOARD_LENGTH][BOARD_HEIGHT];
	create_board(board);
	print_board(board);
	turn(board, 'X');
	print_board(board);
	return 1;
}