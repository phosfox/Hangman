//
// Created by Constantin on 02.08.2018.
//

#ifndef HANGMAN_DICTIONARY_H
#define HANGMAN_DICTIONARY_H

#include <stdlib.h>

char *getRandomWord() {
    srand(time(NULL));
    char *dictionary[57] = {"document",
                                       "northern",
                                       "amoebic",
                                       "planet",
                                       "electric",
                                       "attack",
                                       "houseguest",
                                       "blank",
                                       "knuckles",
                                       "bitter",
                                       "blindly",
                                       "tomato",
                                       "gibberish",
                                       "expert",
                                       "buzz",
                                       "command",
                                       "pink",
                                       "silent",
                                       "knowledge",
                                       "way",
                                       "man",
                                       "bouncy",
                                       "lucky",
                                       "pail",
                                       "activity",
                                       "remove",
                                       "tangy",
                                       "damp",
                                       "flame",
                                       "superficial",
                                       "scene",
                                       "birds",
                                       "aggressive",
                                       "coil",
                                       "order",
                                       "truculent",
                                       "nimble",
                                       "decide",
                                       "flashy",
                                       "add",
                                       "quixotic",
                                       "reproduce",
                                       "bruise",
                                       "lumpy",
                                       "knot",
                                       "jazzy",
                                       "writer",
                                       "color",
                                       "dislike",
                                       "encouraging",
                                       "homeless",
                                       "soggy",
                                       "judge",
                                       "abrupt",
                                       "tired",
                                       "control",
                                       "friction"};

    int rng = rand() % 57;
    return dictionary[rng];
}

#endif //HANGMAN_DICTIONARY_H
