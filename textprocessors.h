//
// Created by kaleb on 2021-05-20.
//

#ifndef FINAL_PROJECT_TEXTPROCESSORS_H
#define FINAL_PROJECT_TEXTPROCESSORS_H
#include <string>
#include <iostream>
using namespace std;

// Kaleb Text Processors
int count_words(char *text);
int count_numbers(char *text);
void lowercase_letters(char *text);

// Johnny Text Processors
void leet_case(char *text);
void capitalize_letters(char *text);
void capitalize_letters(string &text); 
void search_replace(string &text, string &search, string &replace);

#endif //FINAL_PROJECT_TEXTPROCESSORS_H
