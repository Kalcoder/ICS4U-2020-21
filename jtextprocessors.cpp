//
// Created by kaleb on 2021-05-20.
//

#include "jtextprocessors.h"

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
