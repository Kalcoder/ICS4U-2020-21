//
// Created by kaleb on 2021-05-20.
//

#ifndef FINAL_PROJECT_JTEXTPROCESSORS_H
#define FINAL_PROJECT_JTEXTPROCESSORS_H
#include <string>
#include <map>

// Replacement characters for the leet_case function
extern const std::map<char, std::string> leets;

// Johnny Text Processors

/**
 * Converts a string of text into a leet_case
 *
 * @param text The text to convert
 * @return Converted Text
 */
std::string leet_case(std::string text);

/**
 * Capitalizes all letters from text
 *
 * @param text The text to capitalize
 * @return The capitalized string
 */
std::string capitalize_letters(std::string text);

/**
 * Searches through lowercase text and replaces keywords
 *
 * @param text The string to go through
 * @param search The string to search for
 * @param replace The string to replace with.
 * @return The fully filtered string
 */
std::string search_replace(std::string text, const std::string search, const std::string replace);

#endif //FINAL_PROJECT_JTEXTPROCESSORS_H
