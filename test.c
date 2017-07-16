#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 128

int main(void) {
	char board[3][2] = {0};
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 2; y++) {
			printf("%d ", board[x][y]);
		}
		printf("\n");
	}

}