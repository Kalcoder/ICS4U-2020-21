//
// Created by kaleb on 2021-06-17.
//

#ifndef FINAL_PROJECT_KTEXTPROCESSORS_H
#define FINAL_PROJECT_KTEXTPROCESSORS_H
#include <string>

// Kaleb Text Processors

/**
 * Counts the words in the provided text
 *
 * @param text Text to count words in
 * @return The counted words in <code>text</code>
 */
int count_words(const std::string text);

/**
 * Counts the numbers in the provided text
 *
 * @param text Text to count numbers in
 * @return The counted numbers in <code>text</code>
 */
int count_digits(const std::string text);

/**
 * Converts a <code>std::string</code> to lowercase
 *
 * @param text Text to make lowercase
 * @return The inputted text in all lowercase
 */
std::string lowercase_letters(std::string text);

#endif //FINAL_PROJECT_KTEXTPROCESSORS_H
