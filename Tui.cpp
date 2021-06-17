//
// Created by kaleb on 2021-06-16.
//

#include "Tui.h"
#include "jtextprocessors.h"
#include "ktextprocessors.h"

void Tui::render() {
    // Initial input box
    auto input = Input(&text_to_process, "Text to process");

    // Checkboxes to enable each text processor
    auto c_lowercase_letters    = Checkbox(L"Enabled", &enable_lowercase_letters);
    auto c_capitalize_letters   = Checkbox(L"Enabled", &enable_capitalize_letters);
    auto c_leet_case            = Checkbox(L"Enabled", &enable_leet_case);
    auto c_count_words          = Checkbox(L"Enabled", &enable_count_words);
    auto c_count_numbers        = Checkbox(L"Enabled", &enable_count_numbers);
    auto c_search_replace       = Checkbox(L"Enabled", &enable_search_replace);

    // Search and replace is a pain

    auto i_search  = Input(&searchText,  L"Search...");
    auto i_replace = Input(&replaceText, L"Replace...");

    // Define the layout for the inputs (Container::Vertical is ↕, Container::Horizontal is <->)
    auto component_container = Container::Vertical({
        input,
        Container::Horizontal({
            c_lowercase_letters,
            c_capitalize_letters,
            c_leet_case
        }),
        Container::Horizontal({
            c_count_words,
            c_count_numbers,
            Container::Vertical({
                Container::Horizontal({
                    i_search,
                    i_replace
                }),
                c_search_replace
            })
        })
    });

    // Build the main window
    auto document = Renderer(component_container, [&] {
        return window(text(L"Final Project"), vbox({ // Window with a title "Final Project" that contains...:
                            hbox({text(L"Input: "), input->Render()}) | hcenter, // Horizontally centered input box with a label of "Input: "
                            separator(), // Separator
                            hbox({
                                     TextProcessorWindow(L"To Lowercase", enable_lowercase_letters, c_lowercase_letters,  lowercase_letters),  // Custom text processor window with the title "To Lowercase" that controls lowercase_letters
                                     TextProcessorWindow(L"To Uppercase", enable_capitalize_letters, c_capitalize_letters, capitalize_letters), // Custom text processor window with the title "To Uppercase" that controls capitalize_letters
                                     TextProcessorWindow(L"To Leet-case", enable_leet_case, c_leet_case,          leet_case),          // Custom text processor window with the title "To Leet-case" that controls leet_case
                            }),
                            hbox({
                                     TextCounterWindow(L"Count Words",      enable_count_words,   c_count_words,   count_words),      // Custom text counter window with the title "Count Words" that controls count_words
                                     TextCounterWindow(L"Count Numbers",    enable_count_numbers, c_count_numbers, count_numbers),  // Custom text counter window with the title "Count Numbers" that controls count_numbers

                                     TextSearchReplaceWindow(L"Search & Replace", enable_search_replace, c_search_replace, i_search, i_replace, search_replace), // Custom search & replace window with the title "Search & Replace" that controls search_replace
                            })
            })
        );
    });

    // Generate the output and loop Tui::render
    auto screen = ScreenInteractive::TerminalOutput();
    screen.Loop(document);
}

Element Tui::TextProcessorWindow(std::wstring description, bool & controlling_bool, Component checkbox, std::function<std::string(std::string)> processor) {
    return window(text(description), vbox({
               text(controlling_bool ? str_to_wstr(processor(wstr_to_str(text_to_process))) : L"") | border | hcenter | color(controlling_bool ? Color::White : Color::GrayDark),
               checkbox->Render() | hcenter
        })
    ) | flex;
}

Element Tui::TextCounterWindow(std::wstring description, bool & controlling_bool, Component checkbox, std::function<int(std::string)> processor) {
    return window(text(description), vbox({
            text(controlling_bool ? std::to_wstring(processor(wstr_to_str(text_to_process))) : L"") | border | hcenter | color(controlling_bool ? Color::White : Color::GrayDark),
            checkbox->Render() | hcenter
        })
    ) | flex;
}

Element Tui::TextSearchReplaceWindow(std::wstring description, bool & controlling_bool, Component checkbox, Component searchInput, Component replaceInput, std::function<std::string(std::string, std::string, std::string)> processor) {
    return window(text(description), vbox({
             hbox({
                      text(L"Search: "),
                      searchInput->Render(),
                      separator(),
                      text(L"Replace: "),
                      replaceInput->Render()
                  }) | hcenter,
             text(controlling_bool ? str_to_wstr(processor(wstr_to_str(text_to_process), wstr_to_str(searchText), wstr_to_str(replaceText))) : L"") | border | hcenter | color(controlling_bool ? Color::White : Color::GrayDark),
             checkbox->Render() | hcenter
         })
    ) | flex;
}
