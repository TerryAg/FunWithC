#define BOARD_SIZE 3
#define MAX_LINE 128

// board_funcs.c
void create_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);

// end.c
int game_complete(int curr_player, int scoring[BOARD_SIZE*2 + 2], int turns_done);

// turn.c
void turn(char board[BOARD_SIZE][BOARD_SIZE], int curr_player, int pattern, int scoring[BOARD_SIZE*2 + 2]);