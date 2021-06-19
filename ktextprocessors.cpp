//
// Created by kaleb on 2021-06-17.
//

#include "ktextprocessors.h"

int count_words(const std::string text) {
    bool startedWord = false; // Marker for checking if we started a word
    int count = 0; // Total word count

    // Loop through the inputted text until we reach the null-terminator (guaranteed to be there as we're working with std::string's)
    for (int i = 0; text[i] != '\0'; i++) {
        char currentChar = text[i];
        // Check if the current character controls the end of a word (punctuation, whitespace)
        if (isspace(currentChar) || ispunct(currentChar)) {
            // If we were in a word, set the startedWord marker to false to signify we are no longer in a word
            if (startedWord) {
                startedWord = false;
            }
        // If the current character is some letter and we haven't already started a new word, increase the word count and set startedWord to true
        } else if (isalpha(currentChar) && !startedWord) {
            count++;
            startedWord = true;
        }
    }
    // Return the final word count
    return count;
}

int count_digits(const std::string text) {
    int count = 0; // Total number count

    // Loop through the inputted text until we reach the null-terminator (guaranteed to be there as we're working with std::string's)
    for (int i = 0; text[i] != '\0'; i++) {
        // If the current character is a digit, add to the counter
        char currentChar = text[i];
        if (isdigit(currentChar)) {
            count++;
        }
    }
    // Return the final digit count
    return count;
}

std::string lowercase_letters(std::string text) {
    // Loop through the inputted text until we reach the null-terminator (guaranteed to be there as we're working with std::string's)
    for (int i = 0; text[i] != '\0'; i++){
        // Convert the current character into lowercase
        text[i] = tolower(text[i]);
    }
    // Return the converted text
    return text;
}
