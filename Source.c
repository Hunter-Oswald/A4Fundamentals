// software fundamentals - A4 - number guessing game
// Hunter Oswald

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// ask for user input
	int mysteryNum = 0;
	int NumOfGuesses = 0;
	int Guesses[6] = { 0, 0, 0, 0, 0, 0 };
	
	// verify input
	while (mysteryNum < 1 || mysteryNum > 1000) {
		printf("Please enter the mystery number: ");
		if (scanf("%d", &mysteryNum) != 1) {
			printf("Bad Input");
			exit(1);
		}
	}
	printf("\n");
	do
	{
		// (step 2) display number of failed guesses (starts at 0)
		// display the numbers that have been guessed
		printf("Number of failed guesses: %d\n", NumOfGuesses);
		printf("Guesses: ");
		for (int i = 0; i < 6; i++) {
			if (Guesses[i] != 0) {
				printf("%d ", Guesses[i]);
			}
		}
		printf("\n");

		// get a guess from the player
		printf("Enter a guess: ");
		if (scanf("%d", &Guesses[NumOfGuesses]) != 1) {
			printf("Bad Input.\n");
			exit(1);
		}
		printf("\n");

		if (Guesses[NumOfGuesses] != (int)Guesses[NumOfGuesses]) {
			// if the guess isn't a number, and they have made less than 6 guesses, restart at step 2 "Incorrect input
			// if the guess isn't a number and they have made 6 guesses, end the game and display "You Lose"
			if (NumOfGuesses < 5) {
				printf("Incorrect input. Guess must be a number.\n");
				
			}
			else {
				printf("You Lose.\n");
				
			}
		} else if (Guesses[NumOfGuesses] > 1000 || Guesses[NumOfGuesses] < 1) {
			// If guess outside of range, "Guess was outside of range. Must be between 1-1000 (inclusive)"
			// If guesses < 6, restart at step 2. If guesses = 6, end the game "You Lose"
			if (NumOfGuesses < 5) {
				printf("Incorrect input. Guess must be between 1 and 1000 (inclusive)\n");
				
			}
			else {
				printf("You Lose.\n");
				
			}
		} else if (Guesses[NumOfGuesses] < mysteryNum) {
			// if guess is within range and below the mystery number, tell the user their guess was too low
			// if guesses < 6, restart at step 2. Otherwise end the game and they lose
			printf("Your guess was too low.\n");
			if (NumOfGuesses < 5) {
				
			}
			else {
				printf("You Lose.\n");
				
			}
		} else if (Guesses[NumOfGuesses] == mysteryNum) {
			// if the guess is the same as the mystery number, Lets user know they won and exits game
			printf("You Win!\n");
			exit(1);
		} else {
			printf("Incorrect guess.\n");
			
		}
		NumOfGuesses = NumOfGuesses + 1;

	} while (NumOfGuesses < 6);
	
	return (0);
}
