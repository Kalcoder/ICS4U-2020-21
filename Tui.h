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

/**
 * Base text UI class. Used for rendering the text UI and interfacing with the <a href=https://github.com/ArthurSonzogni/FTXUI>FTXUI library</a>
 */
class Tui {
public:
    /**
     * Renders the text UI
     */
    void render();
private:
    // Variables controlling the std::wstring to process and the std::wstring's to search/replace with (only used for search/replace)
    std::wstring text_to_process;
    std::wstring searchText;
    std::wstring replaceText;

    // Booleans to control if each processor should run
    bool enable_count_words         = false;
    bool enable_count_digits        = false;
    bool enable_lowercase_letters   = false;
    bool enable_leet_case           = false;
    bool enable_capitalize_letters  = false;
    bool enable_search_replace      = false;

    // Conversions from std::string <-> std::wstring
    std::wstring_convert<convert_t, wchar_t> converter;

    /**
     * Converts a std::string to a std::wstring
     *
     * @param str The std::string to convert
     * @return The converted std::wstring
     * @see Tui::wstr_to_str
     */
    std::wstring str_to_wstr(std::string str) {
        return converter.from_bytes(str);
    }
    /**
     * Converts a std::wstring to a std::string
     *
     * @param wstr the std::wstring to convert
     * @return The converted std::string
     * @see Tui::str_to_wstr
     */
    std::string wstr_to_str(std::wstring wstr) {
        return converter.to_bytes(wstr);
    }

    /**
     * Creates a new window Element that contains the inputted title, the processed text if the checkbox is turned on, and the checkbox to control the processor
     *
     * @param title The title of the window
     * @param controlling_bool The bool to control if <code>processor</code> should run
     * @param checkbox The checkbox <code>Component</code> to set <code>controlling_bool</code>
     * @param processor The string processor to run on <code>text_to_process</code>
     * @return New window Element that contains the inputted title, the processed text if the checkbox is turned on, and the checkbox to control the processor
     */
    Element TextProcessorWindow(std::wstring title, bool & controlling_bool, Component checkbox, std::function<std::string(std::string)> processor);

    /**
    * Creates a new window Element that contains the inputted title, the counted text if the checkbox is turned on, and the checkbox to control the processor
    *
    * @param title The title of the window
    * @param controlling_bool The bool to control if <code>processor</code> should run
    * @param checkbox The checkbox <code>Component</code> to set <code>controlling_bool</code>
    * @param processor The string counter to run on <code>text_to_process</code>
    * @return New window Element that contains the inputted title, the processed text if the checkbox is turned on, and the checkbox to control the processor
    */
    Element TextCounterWindow(std::wstring title, bool & controlling_bool, Component checkbox, std::function<int(std::string)> processor);

    /**
     * Creates a new search & replace window Element that contains the inputted title, the search/replace inputs, the replaced text if the checkbox is turned on, and the checkbox to control the search/replace processor
     *
     * @param title The title of the window
     * @param controlling_bool The bool to control if <code>processor</code> should run
     * @param checkbox The checkbox <code>Component</code> to set <code>controlling_bool</code>
     * @param searchInput  The input that controls the text to search for in <code>text_to_process</code>
     * @param replaceInput The input that controls the text to replace in <code>text_to_process</code>
     * @param processor The search & replace processor to run on <code>text_to_process</code>
     * @return  New search & replace window Element that contains the inputted title, the search/replace inputs, the replaced text if the checkbox is turned on, and the checkbox to control the search/replace processor
     */
    Element TextSearchReplaceWindow(std::wstring title, bool & controlling_bool, Component checkbox, Component searchInput, Component replaceInput, std::function<std::string(std::string, std::string, std::string)> processor);
};

#endif //FINAL_PROJECT_TUI_H
