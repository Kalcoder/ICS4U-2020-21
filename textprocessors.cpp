//
// Created by kaleb on 2021-05-20.
//

#include "textprocessors.h"

// Kaleb Text Processors

int count_words(char *text) {
    bool startedWord = false;
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        char currentChar = text[i];
        if (isspace(currentChar) || ispunct(currentChar)) {
            if (startedWord) {
                count++;
                startedWord = false;
            }
        } else if (isalpha(currentChar)) {
            startedWord = true;
        }
    }
    return count;
}

int count_numbers(char *text) {
    return 0;
}

void lowercase_letters(char *text) {

}

// Johnny Text Processors

void leet_case(char *text) {

}

void capitalize_letters(char *text) {

}

void search_replace(char *text, char *search, char *replace) {

}
