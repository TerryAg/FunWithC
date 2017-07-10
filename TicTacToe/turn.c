#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tictactoe.h"

void turn(char board[BOARD_SIZE][BOARD_SIZE], int curr_player, int pattern, int scoring[BOARD_SIZE*2 + 2]) {
	char input[MAX_LINE];
	int choice, num;
	int row, col;
	int score = curr_player == 1 ? 1 : -1;

	char *end;
	printf("Player %d: Pick a square: ", curr_player);
	while (fgets(input, MAX_LINE, stdin) != '\0') {
		choice = strtol(input, &end, 10);
		row = (choice - 1) / BOARD_SIZE;
		col = (choice - 1) % BOARD_SIZE;
		if (end == input) {
			printf("That's not a number! ");
		} else if ((choice < 1) || (choice > BOARD_SIZE*BOARD_SIZE)) {
			printf("That number is out of range! ");
		} else if (board[row][col] != ' ') {
			printf("That spot is already occupied! ");
		} else {
			board[row][col] = pattern;
			scoring[row] += score; // row n
			scoring[BOARD_SIZE + col] += score; // col n;
			if (row == col) {
				scoring[2*BOARD_SIZE] += score; // topleft diag
			}
			if (BOARD_SIZE - col - 1 == row) {
				scoring[2*BOARD_SIZE + 1] += score; //topright
			}
			return;
		}
	}
	printf("\nQuitting...\n"); // CTRL+D has been hit
	exit(0);
}