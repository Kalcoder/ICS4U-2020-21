//
// Created by kaleb on 2021-05-20.
//

#include "textprocessors.h"

// Kaleb Text Processors

int count_words(const char *text) {
    return 0;
}

int count_numbers(const char *text) {
    return 0;
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
