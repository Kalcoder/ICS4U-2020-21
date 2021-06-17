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


void search_replace(string &text, const string search, const string replace) {
    unsigned int skips = 0; // Number of characters to skip if we just replaced something
    for (int i = 0; text[i] != '\0'; ++i) { // going through each character of text
        if (skips > 0) { // If we need to skip
            skips--;
            continue; // Skip
        }
        bool match = true;
        for (int j = 0; search[j] != '\0'; ++j) {
            if (text[i + j] != search[j]) {
                match = false;
                break;
            }
        }
        if (!match) continue;
        text = text.replace(i, search.size(), replace);
        skips = replace.size() - 1; // Skip the newly added characters (-1 cause we just finished a character)
    }
}
