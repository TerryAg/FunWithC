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
	char input = '\0';
	char *end;
	int choice, num;
	printf("Player %d: Pick a column. ");
	while (fgets(input, MAX_LINE, stdin) != '\0') {
		choice = strtol(input, &end, 10);
		if (end == input) {
			printf("That's not a number! ");
			continue;
		}
		num = (int) choice; // Since strtol returns a long.
		if ((choice < 1) || (choice > BOARD_LENGTH)) {
			printf("That number is out of range! ");
			continue;
		}
		if (board[BOARD_HEIGHT-1][choice] != ' ') {
			printf("Column is full! ")
			continue;
		}
		
	}
}

int main(void) {
	char board[BOARD_LENGTH][BOARD_HEIGHT];
	create_board(board);
	print_board(board);

}