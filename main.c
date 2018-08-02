#include <stdio.h>
#include <mem.h>
#include <conio.h>
#include <stdlib.h>

int LIFES = 5;
char wordToGuess[100];
char hiddenWord[100] = {'_'};

int guessedCompleteWord() {
    for (int i = 0; hiddenWord[i] != '\0'; i++) {
        if (hiddenWord[i] == '_') {
            return 0;
        }
    }
    return 1;
}

int guessIsCorrect(char c) {
    int guessCorrect = 0;
    for (int i = 0; wordToGuess[i] != '\0'; i++) {
        if (wordToGuess[i] == c) {
            guessCorrect = 1;
            return guessCorrect;
        }
    }
    return guessCorrect;
}

void replaceChar(char c) {
    for (int i = 0; wordToGuess[i] != '\0'; i++) {
        if (wordToGuess[i] == c) {
            hiddenWord[i] = c;
        }
    }
}

void loadGame() {
    printf("**HANGMAN**\n");
    printf("***********\n");
    char guess;
    fgets(wordToGuess, 100, stdin);

    int end = 0;
    for (int i = 0; wordToGuess[i] != '\0'; i++) {
        hiddenWord[i] = '_';
        end = i;
    }
    hiddenWord[end] = '\0';
    printf(hiddenWord);
    printf("\n");

    do {
        printf("Take a guess!: ");
        scanf("%c",&guess);
        getchar(); //Consumes newline

        if (guessIsCorrect(guess)) {
            replaceChar(guess);
            printf("Correct!\n");
            puts(hiddenWord);
        } else {
            LIFES -= 1;
            printf("Incorrect! You have %d life(s) left.\n", LIFES);
            puts(hiddenWord);
        }

        if (guessedCompleteWord()) {
            break;
        }
    }while (LIFES > 0);
    printf("Finished!\n");
}

int main() {
    loadGame();

    return 0;
}