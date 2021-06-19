//
// Created by kaleb on 2021-06-17.
//

#include "ktextprocessors.h"

int count_words(const std::string text) {
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

int count_digits(const std::string text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        char currentChar = text[i];
        if (isdigit(currentChar)) {
            count++;
        }
    }
    return count;
}

std::string lowercase_letters(std::string text) {
    for (int i = 0; text[i] != '\0'; i++){
        text[i] = tolower(text[i]);
    }
    return text;
}
