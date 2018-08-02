#include <stdio.h>
#include <mem.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int LIFES = 5;
char wordToGuess[100];
char hiddenWord[100] = {'_'};

char *getRandomWord() {
    srand(time(NULL));
    char *dictionary[17] = {"document", "northern", "amoebic", "planet", "electric", "attack", "houseguest", "blank",
                            "knuckles", "bitter", "blindly", "tomato", "gibberish", "expert", "buzz", "command",
                            "pink"};
    int rng = rand() % 17;
    return dictionary[rng];
}

void printWordWithSpaces(char * word){
    for (int i = 0; word[i] != '\0'; ++i) {
        printf("%c ", word[i]);
    }
}

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
    printf("Words are in english\n");
    printf("**HANGMAN**\n");
    printf("***********\n");
    char guess;
    //fgets(wordToGuess, 100, stdin);
    strcpy(wordToGuess, getRandomWord());

    int end = 0;
    for (int i = 0; wordToGuess[i] != '\0'; i++) {
        hiddenWord[i] = '_';
        end = i;
    }
    hiddenWord[end] = '\0';
    //printf(hiddenWord);
    printWordWithSpaces(hiddenWord);
    printf("\n");
    printf("***********\n");
    printf("\n");

    do {
        printf("Take a guess!: ");
        scanf("%c", &guess);
        getchar(); //Consumes newline

        if (guessIsCorrect(guess)) {
            replaceChar(guess);
            printf("Correct!\n");
            printWordWithSpaces(hiddenWord);
            printf("\n");
            //puts(hiddenWord);
        } else {
            LIFES -= 1;
            printf("Incorrect! You have %d life(s) left.\n", LIFES);
            printWordWithSpaces(hiddenWord);
            printf("\n");
            //puts(hiddenWord);
        }

        if (guessedCompleteWord()) {
            break;
        }
    } while (LIFES > 0);
    printf("Finished!\n");
    printf("The word was: %s\n", wordToGuess);
    printf("Press any key to end.");
    getchar();
}

int main() {
    loadGame();

    return 0;
}