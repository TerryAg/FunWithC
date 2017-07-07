#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"

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