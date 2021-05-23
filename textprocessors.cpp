//
// Created by kaleb on 2021-05-20.
//

#include "textprocessors.h"

// Kaleb Text Processors

int count_words(const char *text) {
    bool startedWord = false;
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        char currentChar = text[i];
        if (isspace(currentChar) || ispunct(currentChar)) {
            if (startedWord) {
                startedWord = false;
            }
        } else if (isalpha(currentChar) && !startedWord) {
            count++;
            startedWord = true;
        }
    }
    return count;
}

int count_numbers(const char *text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        char currentChar = text[i];
        if (isdigit(currentChar)) {
            count++;
        }
    }
    return count;
}

void lowercase_letters(char * const text) {
    for (int i = 0; text[i] != '\0'; i++){
        text[i] = tolower(text[i]);
    }
}

// Johnny Text Processors

void leet_case(char *text) {

}

void capitalize_letters(char *text) {

}

void search_replace(char *text, char *search, char *replace) {

}
