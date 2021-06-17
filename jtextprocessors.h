//
// Created by kaleb on 2021-05-20.
//

#ifndef FINAL_PROJECT_JTEXTPROCESSORS_H
#define FINAL_PROJECT_JTEXTPROCESSORS_H
#include <string>
#include <map>
#include <iostream>
using namespace std;

extern const std::map<char, std::string> leets;

// Kaleb Text Processors
int count_words(char *text);
int count_numbers(char *text);
void lowercase_letters(string text);

// Johnny Text Processors
void leet_case(string &text);
void capitalize_letters(char *text);
void capitalize_letters(string &text); 
void search_replace(string &text, const string search, const string replace);

#endif //FINAL_PROJECT_JTEXTPROCESSORS_H
