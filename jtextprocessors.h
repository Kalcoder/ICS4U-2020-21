//
// Created by kaleb on 2021-05-20.
//

#ifndef FINAL_PROJECT_JTEXTPROCESSORS_H
#define FINAL_PROJECT_JTEXTPROCESSORS_H
#include <string>
#include <map>
#include <iostream>

extern const std::map<char, std::string> leets;

// Johnny Text Processors
void leet_case(std::string &text);
void capitalize_letters(char *text);
void capitalize_letters(std::string &text);
void search_replace(std::string &text, const std::string search, const std::string replace);

#endif //FINAL_PROJECT_JTEXTPROCESSORS_H
