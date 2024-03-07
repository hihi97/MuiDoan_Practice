#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Function to generate a random 4-digit magic number
int generateMagicNumber() {
    srand(time(NULL));
    return rand() % 9999 + 1000;
}

// Function to check if the guessed number matches the magic number
void checkGuess(int magicNumber, int guess) {
    int magicDigits[4], guessDigits[4];
    int i, matched = 0;

    // Separate  digits of magic number
    for (i = 3; i >= 0; i--) {
        magicDigits[i] = magicNumber % 10;
        magicNumber /= 10;
    }

    // Separate digits of guess
    for (i = 3; i >= 0; i--) {
        guessDigits[i] = guess % 10;
        guess /= 10;
    }

    // Check if user guess matching with magicNumber
    for (i = 0; i < 4; i++) {
        if (magicDigits[i] == guessDigits[i]) { // check if digit at position i between magicNumber and user's matched 
            printf("%d", magicDigits[i]);      // Print matched digit
            matched++;
        } else {
            printf("-");        // remaining position does not match, display '-'
        }
    }

}

int main() {
    char playerName[MAX_NAME_LENGTH];
   
    printf("Enter your name: ");
    fgets(playerName, MAX_NAME_LENGTH, stdin);
  
    printf("Welcome to guessing game, %s!", playerName);
	
	int magicNumber = generateMagicNumber();
    int totalGuesses = 0;
    int correctGuesses = 0;
    int round = 1;
    int guess;
	
    while (1) {       

        printf("\tRound %d\n", round);

        while (1) {
            printf("Enter your guess (4 digits): ");
            scanf("%d", &guess);
            totalGuesses++;
            
            if ((guess < 1000)||(guess>9999)){
            	continue;
			}else{}

            // Check if guess is correct
            
            printf("Matching check: ");
            checkGuess(magicNumber, guess);
            printf("\n");

            if (magicNumber == guess) {
                printf("Congratulations, you've guessed the magic number: %d\n, round %d", magicNumber, round);
                correctGuesses++;
                break;
            }
        }

        float rate = 100*(float)correctGuesses / totalGuesses;
        printf("Lucky ratio: %.2f %\n", rate);

        char playAgain;
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
        else {
             round++;
             continue;
            
        }
    }

    return 0;
}
