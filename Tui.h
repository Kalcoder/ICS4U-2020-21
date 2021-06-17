//
// Created by kaleb on 2021-06-16.
//

#ifndef FINAL_PROJECT_TUI_H
#define FINAL_PROJECT_TUI_H

#include <string>
#include <codecvt>
#include <locale>

#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/component.hpp"

// This class uses a converter wstring <-> string
// Taken from https://riptutorial.com/cplusplus/example/4190/conversion-to-std--wstring

using namespace ftxui;
using convert_t = std::codecvt_utf8<wchar_t>;

class Tui {
public:
    void render();
private:
    std::wstring text_to_process;
    std::wstring searchText;
    std::wstring replaceText;

    bool enable_count_words         = false;
    bool enable_count_numbers       = false;
    bool enable_lowercase_letters   = false;
    bool enable_leet_case           = false;
    bool enable_capitalize_letters  = false;
    bool enable_search_replace      = false;

    std::wstring_convert<convert_t, wchar_t> converter;

    std::wstring str_to_wstr(std::string str) {
        return converter.from_bytes(str);
    }
    std::string wstr_to_str(std::wstring wstr) {
        return converter.to_bytes(wstr);
    }

    Element TextProcessorWindow(std::wstring description, bool & controlling_bool, Component checkbox, std::function<std::string(std::string)> processor);
    Element TextCounterWindow(std::wstring description, bool & controlling_bool, Component checkbox, std::function<int(std::string)> processor);
    Element TextSearchReplaceWindow(std::wstring description, bool & controlling_bool, Component checkbox, Component searchInput, Component replaceInput, std::function<std::string(std::string, std::string, std::string)> processor);
};

#endif //FINAL_PROJECT_TUI_H
