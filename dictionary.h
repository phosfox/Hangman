//
// Created by Constantin on 02.08.2018.
//

#ifndef HANGMAN_DICTIONARY_H
#define HANGMAN_DICTIONARY_H

#include <stdlib.h>

char *getRandomWord() {
    srand(time(NULL));
    char *dictionary[17] = {"document", "northern", "amoebic", "planet", "electric", "attack", "houseguest", "blank",
                            "knuckles", "bitter", "blindly", "tomato", "gibberish", "expert", "buzz", "command",
                            "pink"};
    int rng = rand() % 17;
    return dictionary[rng];
}

#endif //HANGMAN_DICTIONARY_H
