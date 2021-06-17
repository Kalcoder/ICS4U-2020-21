//
// Created by kaleb on 2021-05-20.
//

#ifndef FINAL_PROJECT_TEXTPROCESSORS_H
#define FINAL_PROJECT_TEXTPROCESSORS_H
#include <string>

// Kaleb Text Processors
int count_words_char(char *text);
int count_words(std::string text);
int count_numbers_char(char *text);
int count_numbers(std::string text);
std::string lowercase_letters_char(char *text);
std::string lowercase_letters(std::string text);

// Johnny Text Processors
std::string leet_case_char(char *text);
std::string leet_case(std::string text);
std::string capitalize_letters_char(char *text);
std::string capitalize_letters(std::string text);
std::string search_replace_char(char *text, char *search, char *replace);
std::string search_replace(std::string text, std::string search, std::string replace);

#endif //FINAL_PROJECT_TEXTPROCESSORS_H
