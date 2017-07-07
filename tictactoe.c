#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 3
#define MAX_LINE 128

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
		choice = strtol(input, &end, 10);
		if (end == input) {
			printf("That's not a number! ");
			continue;
		}
		num = (int) choice; // Since strtol returns a long.
		if ((choice < 1) || (choice > BOARD_SIZE*BOARD_SIZE)) {
			printf("That number is out of range! ");
			continue;
		}
		row = (choice - 1) / BOARD_SIZE;
		col = (choice - 1) % BOARD_SIZE;
		if (board[row][col] != ' ') {
			printf("That spot is already occupied! ");
			continue;
		}
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
	printf("\nQuitting...\n"); // CTRL+D has been hit
	exit(0);
}

void create_board(char board[BOARD_SIZE][BOARD_SIZE]) {
	for (int x = 0; x < BOARD_SIZE; x++) {
		for (int y = 0; y < BOARD_SIZE; y++) {
			board[x][y] = ' ';
		}
	}
}

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