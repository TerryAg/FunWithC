#include <stdio.h>
#include <stdlib.h>

#define BOARD_LENGTH 7
#define BOARD_HEIGHT 6
#define MAX_LINE 128

void create_board(char board[BOARD_LENGTH][BOARD_HEIGHT]) {
	// Creates the board, where each sub-array is a column
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
	// Prints the board
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
	return -1; // Shouldn't happen
}

int game_over(char board[BOARD_LENGTH][BOARD_HEIGHT], char pattern, int turns_done,
				int x, int y) {
	// Determines if the game is over by seeing if any
	// four in a row at the most recent placement
	if (turns_done < 7) {
		return 0;
	}
	
	// Check around the point and see if 4 in a row
	 
	if (x > 2) {
		// Then we can check upwards
		if ((board[x-1][y] == pattern) && 
		(board[x-2][y] == pattern) &&
		(board[x-3][y] == pattern)) {
			return 1;
		}
	}

	if (y > 2) {
		// can check left
		if ((board[x][y-1] == pattern) && 
		(board[x][y-2] == pattern) &&
		(board[x][y-3] == pattern)) {
			return 1;
		}

	}

	if (x < 4) {
		// can check down
		if ((board[x+1][y] == pattern) && 
		(board[x+2][y] == pattern) &&
		(board[x+3][y] == pattern)) {
			return 1;
		}
	}
	if (y < 3) {
		// can check right
		if ((board[x][y+1] == pattern) && 
		(board[x][y+2] == pattern) &&
		(board[x][y+3] == pattern)) {
			return 1;
		}
	}

	if ((x < 4) && (y < 3)) {
		// check diag rightdown
		if ((board[x+1][y+1] == pattern) && 
		(board[x+2][y+2] == pattern) &&
		(board[x+3][y+3] == pattern)) {
			return 1;
		}	
	}

	if ((x > 2) && (y > 2)) {
		// check diag leftup
		if ((board[x-1][y-1] == pattern) && 
		(board[x-2][y-2] == pattern) &&
		(board[x-3][y-3] == pattern)) {
			return 1;
		}	
	}

	if ((x > 2) && (y < 3)) {
		// check diag rightup
		if ((board[x-1][y+1] == pattern) && 
		(board[x-2][y+2] == pattern) &&
		(board[x-3][y+3] == pattern)) {
			return 1;
		}	
	}

	if ((x < 4) && (y > 2)) {
		// check diag leftdown

		if ((board[x+1][y-1] == pattern) && 
		(board[x+2][y-2] == pattern) &&
		(board[x+3][y-3] == pattern)) {
			return 1;
		}	
	}

	if (turns_done == BOARD_HEIGHT*BOARD_LENGTH) {
		printf("Draw!\n");
		return 1;
	}
	return 0;
}

void turn(char board[BOARD_LENGTH][BOARD_HEIGHT], char pattern,
			int *x_coord, int *y_coord) {
	// Plays the current player's turn
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
			*x_coord = choice;
			*y_coord = top_of_col(board, choice);
			board[*x_coord][*y_coord] = pattern;
			return;
		}
	}
	printf("\nQuitting...\n");
	exit(0);
}

int main(void) {
	char board[BOARD_LENGTH][BOARD_HEIGHT];
	char pattern = '\0';
	int curr_player = 1;
	int turns_done = 0;
	int x_coord, y_coord;

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
		turn(board, pattern, &x_coord, &y_coord);
		turns_done++;
		print_board(board);
		if (game_over(board, pattern, turns_done, x_coord, y_coord)) {
			break;
		}
		pattern = pattern == 'O' ? 'X' : 'O';
		curr_player = curr_player == 1 ? 2 : 1;
	}
	
	return 1;
}