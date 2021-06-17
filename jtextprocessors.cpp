//
// Created by kaleb on 2021-05-20.
//

#include "jtextprocessors.h"
#include "ktextprocessors.h"

// Johnny Text Processors

const std::map<char, std::string> leets = {
    {'a', "4"},
    {'b', "6"},
    {'c', "["},
    {'d', "|)"},
    {'e', "3"},
    {'f', "|="},
    {'g', "9"},
    {'h', "#"},
    {'i', "!"},
    {'j', "._|"},
    {'k', "|<"},
    {'l', "1"},
    {'m', "/\\/\\"},
    {'n', "/\\/"},
    {'o', "0"},
    {'p', "|*"},
    {'q', "0_"},
    {'r', "|2"},
    {'s', "5"},
    {'t', "7"},
    {'u', "|_|"},
    {'v', "\\/"},
    {'w', "\\/\\/"},
    {'x', "><"},
    {'y', "`/"},
    {'z', "7_"},
};

std::string leet_case(std::string text) {
    lowercase_letters(text); // Compares everything at lowercase since it's easier
    for (const auto& leet : leets) {
        std::string search(1, leet.first);
        search_replace(text, search, leet.second);
    }
    return text;
}


std::string capitalize_letters(std::string text) {
    for (int i = 0; text[i] != '\0'; ++i) {
        text[i] = (char) toupper(text[i]);
    }
    return text;
}


std::string search_replace(std::string text, const std::string search, const std::string replace) {
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
    return text;
}
