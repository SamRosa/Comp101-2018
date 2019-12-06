/***********************************************
Author: Samuel Rosa
Date: 10/7/18
Purpose: Allows two users to play a game of rock
		paper scissors
Time Spent: 1 hour
***********************************************/

#include <stdio.h>

typedef enum { ROCK, PAPER, SCISSORS } Rps;

Rps playerChoice(int player);
void clear_keyboard_buffer();

int main(int argc, char* argv[]) {

	int playing = 1;
	char input = ' ';

	while (playing) {

		Rps player1 = playerChoice(1);
		Rps player2 = playerChoice(2);

		switch (player1) {

		case ROCK:
			if (player2 == PAPER) {
				printf("Player-2 wins, paper covers rock!\n");
			}
			else if (player2 == SCISSORS) {
				printf("Player-1 wins, rock breaks scissors!\n");
			}
			else {
				printf("It's a tie.\n");
			}
			break;

		case PAPER:
			if (player2 == SCISSORS) {
				printf("Player-2 wins, scissors cuts paper!\n");
			}
			else if (player2 == SCISSORS) {
				printf("Player-1 wins, paper covers rock!\n");
			}
			else {
				printf("It's a tie.\n");
			}
			break;

		case SCISSORS:
			if (player2 == ROCK) {
				printf("Player-2 wins, rock breaks scissors!\n");
			}
			else if (player2 == PAPER) {
				printf("Player-1 wins, scissors cuts paper!\n");
			}
			else {
				printf("It's a tie.\n");
			}
			break;

		}

		printf("Would you like to continue(y/n): ");
		scanf(" %c", &input);
		clear_keyboard_buffer();
		if (input == 'n' || input == 'N') {
			playing = 0;
		}

	}

	return 0;
}

Rps playerChoice(int player) {

	char input = ' ';

	printf("Player-%d, it is your turn.\n", player);
	printf("Please enter your choice (r)ock, (p)aper, or (s)cissors: ");
	scanf(" %c", &input);
	clear_keyboard_buffer();

	while (input != 'r' && input != 'R' &&
		input != 'p' && input != 'P' &&
		input != 's' && input != 'S') {

		printf("I'm sorry, I do not understand that.\n");
		printf("Please enter your choice (r)ock, (p)aper, or (s)cissors: ");
		scanf(" %c", &input);
		clear_keyboard_buffer();

	}

	switch (input) {

	case 'r':
	case 'R':
		return ROCK;
		
	case 'p':
	case 'P':
		return PAPER;

	case 's':
	case 'S':
		return SCISSORS;

	}

}

void clear_keyboard_buffer(void) {

	char c = ' ';

	scanf("%c", &c);
	while (c != '\n') {

		scanf("%c", &c);

	}
}