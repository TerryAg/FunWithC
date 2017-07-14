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
/*
	  bottom					top
	{{' ', ' ', ' ', ' ', ' ', ' '}, // col 1
	 {' ', ' ', ' ', ' ', ' ', ' '}, // col 2
	 {' ', ' ', ' ', ' ', ' ', ' '}, // etc
	 {' ', ' ', ' ', ' ', ' ', ' '},
	 {' ', ' ', ' ', ' ', ' ', ' '},
	 {' ', ' ', ' ', ' ', ' ', ' '},
	 {' ', ' ', ' ', ' ', ' ', ' '}}
*/
void print_board(char board[BOARD_LENGTH][BOARD_HEIGHT]) {
	for (int x = BOARD_HEIGHT-1; x >= 0; x--) {
		for (int y = 0; y < BOARD_LENGTH; y++) {
			printf("|%c", board[y][x]);
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
	for (int x = 0; x < BOARD_HEIGHT; x++) {
		printf("x: %d\n", x);
		if (board[column][x] == ' ') {
			return x;
		}
	}
	return -1; // full col. shouldn't happen
}

int game_over(char board[BOARD_LENGTH][BOARD_HEIGHT]) {
	return 0;
}

void turn(char board[BOARD_LENGTH][BOARD_HEIGHT], char pattern) {
	char input[MAX_LINE];
	char *end;
	int choice, num;
	while (fgets(input, MAX_LINE, stdin) != '\0') {
		choice = strtol(input, &end, 10) - 1;
		if (end == input) {
			printf("That's not a number! ");
		} else if ((choice < 0) || (choice > BOARD_LENGTH-1)) {
			printf("That number is out of range! ");
		} else if (board[choice][BOARD_HEIGHT-1] != ' ') {
			printf("Column is full! ");
		} else {
			board[choice][top_of_col(board, choice)] = pattern;
			return;
		}

	}
}

int main(void) {
	char board[BOARD_LENGTH][BOARD_HEIGHT];
	char pattern = '\0';
	int curr_player = 1;

	create_board(board);
	print_board(board);
	printf("Welcome to Connect Four!\n");
	printf("Player 1: Would you like to be O or X?\n");
	while ((pattern != 'X') && (pattern != 'O')) {
		printf("Please input O or X: ");
		fgets(&pattern, MAX_LINE, stdin);
		if (pattern == '\0') {
			printf("\nQuitting...\n");
			exit(0);
		}
	}
	printf("Player 2 is %c.\n", pattern == 'O' ? 'X' : 'O');
	printf("---------------\n");
	print_board(board);

	while (1) {
		printf("Player %d, pick a column: ", curr_player);
		turn(board, pattern);
		print_board(board);
		if (game_over(board)) {
			break;
		}
		pattern = pattern == 'O' ? 'X' : 'O';
		curr_player = curr_player == 1 ? 2 : 1;
	}
	
	return 1;
}