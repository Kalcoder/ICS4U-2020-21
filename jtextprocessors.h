//
// Created by kaleb on 2021-05-20.
//

#ifndef FINAL_PROJECT_JTEXTPROCESSORS_H
#define FINAL_PROJECT_JTEXTPROCESSORS_H
#include <string>
#include <map>

extern const std::map<char, std::string> leets;

// Johnny Text Processors
std::string leet_case(std::string text);
std::string capitalize_letters(std::string text);
std::string search_replace(std::string text, const std::string search, const std::string replace);

#endif //FINAL_PROJECT_JTEXTPROCESSORS_H
