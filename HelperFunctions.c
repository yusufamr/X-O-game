#include "HelperFunctions.h"
/*
 *[Function name]:X_O_game
 *[description]: it contain the main code of the game
 */
void X_O_game(void) {
	int Arr[3][3] = { 0 };//intalize the 2D matrix game by 0's
	int flagX = 0, flagO = 0; //for determine winner

	for (int i = 0; i < 5; i++) {
		// player 1 (x)
		flagX = player1_Turn(Arr);//check if player 1 wins or no
		if (flagX == 1) {
			//player 1 wins so we print 2D matrix game then break out
			print_game(Arr);
			break;
		} else if (flagX == -1) // if player play in index played before then he must play again
			flagX = player1_Turn(Arr);//check if player 1 wins or no
		print_game(Arr);
		// player 2 (O)
		if (i != 4) {
			flagO = player2_Turn(Arr);//check if player 2 wins or no
			if (flagO == 1) {
				//player  wins so we print 2D matrix game then break out
				print_game(Arr);
				break;
			} else if (flagO == -1)// if player play in index played before then he must play again
				flagO = player2_Turn(Arr);//check if player 2 wins or no
			print_game(Arr);
		}
		if (i == 4)
			printf("Draw");// if it was 4th round and no one wins so it's draw
	}

	if (flagO)
		printf("PLAYER O WINS");// if flag O equal 1 then he won
	else if (flagX)
		printf("PLAYER X WINS");// if flag X equal 1 then he won

}
/*
 *[Function name]:check_Winner
 *[description]: it checks if player won or not
 */
int check_Winner(int Arr[3][3]) {
	// horizontal check
	for (int r = 0; r < 3; r++) {
		if (Arr[r][0] == Arr[r][1] && Arr[r][1] == Arr[r][2] && Arr[r][2] != 0)
			return 1;
	}
	// column check
	for (int c = 0; c < 3; c++) {
		if (Arr[0][c] == Arr[1][c] && Arr[1][c] == Arr[2][c] && Arr[2][c] != 0)
			return 1;
	}
	// diagonal check
	if (Arr[0][0] == Arr[1][1] && Arr[1][1] == Arr[2][2] && Arr[1][1] != 0)
		return 1;
	else if (Arr[0][1] == Arr[1][1] && Arr[1][1] == Arr[2][0] && Arr[1][1] != 0)
		return 1;
	return 0; // if no one won then return 0
}
/*
 *[Function name]:player1_Turn
 *[description]: it control player 1 turn by enter his indices and check if he won or not  , return flagX which determine if he won or not
 */
int player1_Turn(int Arr[3][3]) {
	char *Player_x = "Turn of Player X \n please enter your indices \n";
	char *enter_X = "enter X index : ";
	char *enter_Y = "enter Y index: ";
	int flagX = 0;// flag variable set when player win
	printf("%s", Player_x);
	int Xx, Xy;//indices player will play in
	printf("%s", enter_X);
	scanf("%d", &Xx);
	printf("%s", enter_Y);
	scanf("%d", &Xy);
	if (Arr[Xx][Xy] == 0) {
		Arr[Xx][Xy] = 1;
	} else {//if this indices conatin value then player cannot play here
		printf("Cannot play in this place");
		return -1;
	}
	flagX = check_Winner(Arr);
	return flagX;
}
/*
 *[Function name]:player2_Turn
 *[description]: it control player 2 turn by enter his indices and check if he won or not , return flagO which determine if he won or not
 */
int player2_Turn(int Arr[3][3]) {
	char *Player_O = "Turn of Player O \n please enter your indices \n";
	char *enter_X = "enter X index : ";
	char *enter_Y = "enter Y index: ";
	int flagO = 0;// flag variable set when player win
	printf("%s", Player_O);
	int Ox, Oy;//indices player will play in
	printf("%s", enter_X);
	scanf("%d", &Ox);
	printf("%s", enter_Y);
	scanf("%d", &Oy);
	if (Arr[Ox][Oy] == 0) {
		Arr[Ox][Oy] = 2;
	} else {//if this indices conatin value then player cannot play here
		printf("Cannot play in this place");
		return -1;
	}
	flagO = check_Winner(Arr);
	return flagO;
}
/*
 *[Function name]:print_game
 *[description]: it is reponsible for print 2D matrix game
 */
void print_game(int Arr[3][3]) {
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++)
			printf("%d ", Arr[r][c]);
		printf("\n");
	}
}
