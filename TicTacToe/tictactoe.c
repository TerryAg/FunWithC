#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"

int main(void) {
	char board[BOARD_SIZE][BOARD_SIZE];
	char pattern = '\0';
	int curr_player = 1;
	int scoring[BOARD_SIZE*2 + 2] = {0};
	int turns_done = 0;

	create_board(board);
	printf("Welcome to Tic-Tac-Toe!\n");
	printf("Player 1: Would you like to be O or X?\n");
	while ((pattern != 'X') && (pattern != 'O')) {
		printf("Please input O or X: ");
		fgets(&pattern, MAX_LINE, stdin);
		if (pattern == '\0') {
			printf("\nQuitting...\n");
			exit(0);
		}
	}
	printf("Player 2 is %c.\n", pattern == 'O' ?  'X' : 'O');
	printf("---------------\n");
	print_board(board);

	while (1) {
		turn(board, curr_player, pattern, scoring);
		turns_done++;
		print_board(board);
		if (game_complete(curr_player, scoring, turns_done)) {
			break;
		}
		pattern = pattern == 'O' ?  'X' : 'O';
		curr_player = curr_player == 1 ? 2 : 1;
	}
}