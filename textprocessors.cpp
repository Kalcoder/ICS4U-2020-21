//
// Created by kaleb on 2021-05-20.
//

#include "textprocessors.h"

// Kaleb Text Processors

int count_words(char *text) {
    return 0;
}

int count_numbers(char *text) {
    return 0;
}

void lowercase_letters(char *text) {

}

// Johnny Text Processors

void leet_case(char *text) {

}


void capitalize_letters(char * text) {
    for (int i = 0; text[i] != '\0'; ++i) {
        text[i] = (char) toupper(text[i]);
    }
}

void capitalize_letters(string &text) {
    capitalize_letters(&text[0]);
}
void search_replace(char *text, char *search, char *replace) {

}
