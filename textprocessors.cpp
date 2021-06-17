//
// Created by kaleb on 2021-05-20.
//

#include "textprocessors.h"

// Kaleb Text Processors

int count_words_char(char *text) {
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

int count_words(std::string text) {
    return count_words_char(&text[0]);
}

int count_numbers_char(char *text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        char currentChar = text[i];
        if (isdigit(currentChar)) {
            count++;
        }
    }
    return count;
}

int count_numbers(std::string text) {
    return count_numbers_char(&text[0]);
}

std::string lowercase_letters_char(char *text) {
    for (int i = 0; text[i] != '\0'; i++){
        text[i] = tolower(text[i]);
    }
    return text;
}

std::string lowercase_letters(std::string text) {
    return lowercase_letters_char(&text[0]);
}

// Johnny Text Processors

std::string leet_case_char(char *text) {
    return "test";
}

std::string leet_case(std::string text) {
    return leet_case_char(&text[0]);
}

std::string capitalize_letters_char(char *text) {
    return "test";
}

std::string capitalize_letters(std::string text) {
    return capitalize_letters_char(&text[0]);
}

std::string search_replace_char(char *text, char *search, char *replace) {
    return "test";
}

std::string search_replace(std::string text, std::string search, std::string replace) {
    return search_replace_char(&text[0], &search[0], &replace[0]);
}
