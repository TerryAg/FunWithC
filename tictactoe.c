#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 3
#define MAX_LINE 128

/* void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
	for (int x = 0; x < BOARD_SIZE; x++) {
		printf(" %d %d %d\n", x*3+1, x*3+2, x*3+3);
		for (int y = 0; y < BOARD_SIZE; y++) {
			printf("|%c", board[x][y]);
		}
		printf("|\n");
	}
}*/

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
	for (int x = 1; x <= BOARD_SIZE*BOARD_SIZE; x++) {
		printf(" %d", x);
		if (x % BOARD_SIZE == 0) {
			printf("\n");
			for (int y = 0; y < BOARD_SIZE; y++) {
				printf("|%c", board[(x/BOARD_SIZE) - 1][y]);
			}
			printf("|\n");
		}
	}
}

int game_complete(int curr_player, int scoring[BOARD_SIZE*2 + 2], int turns_done) {
	for (int x = 0; x < BOARD_SIZE*2 + 2; x++) {
		if (abs(scoring[x]) == BOARD_SIZE) {
			printf("Player %d wins!!\n", curr_player);
			return 1;
		}
	}
	if (turns_done == BOARD_SIZE*BOARD_SIZE) {
		printf("Draw!\n");
		return 1;
	}
	return 0;
}

void turn(char board[BOARD_SIZE][BOARD_SIZE], int curr_player, int pattern, int scoring[BOARD_SIZE*2 + 2]) {
	char input[MAX_LINE];
	int choice, num;
	int row, col;
	int score = curr_player == 1 ? 1 : -1;

	char *end;
	printf("Player %d: Pick a square: ", curr_player);
	while (fgets(input, MAX_LINE, stdin) != '\0') {
		choice = strtol(input, &end, 10); // does not differentiate 0 and incorrect input
		// printf("int: %d\n", choice);
		if (end == input) {
			printf("That's not a number! ");
		} else {
			num = (int) choice; // Since strtol returns a long.
			if ((choice < 1) || (choice > 9)) {
				printf("That number is out of range! ");
			} else if (board[(choice - 1) / 3][(choice - 1) % 3] != ' ') {
				printf("That spot is already occupied! ");
			} else {
				row = (choice - 1) / 3;
				col = (choice - 1) % 3;

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
		continue;
	}
	printf("\nQuitting...\n"); // CTRL+D has been hit
	exit(0);
}

int main(void) {
	char board[BOARD_SIZE][BOARD_SIZE] = {{' ', ' ', ' '},
										  {' ', ' ', ' '},
										  {' ', ' ', ' '}};
	char pattern = '\0';
	int curr_player = 1;
	int scoring[BOARD_SIZE*2 + 2] = {0};
	int turns_done = 0;
	printf("Welcome to Tic-Tac-Toe!\n");
	printf("Player 1: Would you like to be O or X?\n");
	while ((pattern != 'X') && (pattern != 'O')) {
		printf("Please input O or X: ");
		fgets(&pattern, MAX_LINE, stdin);
	}
	pattern = pattern == 'O' ?  'X' : 'O';
	printf("Player 2 is %c.\n", pattern);
	printf("---------------\n");
	print_board(board);

	while (1) {
		pattern = pattern == 'O' ?  'X' : 'O'; // need to do this first
		turn(board, curr_player, pattern, scoring);
		turns_done++;
		print_board(board);
		if (game_complete(curr_player, scoring, turns_done)) {
			break;
		}
		curr_player = curr_player == 1 ? 2 : 1;
	}

}