cmake_minimum_required(VERSION 3.19)

# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        # Specify a GIT_TAG here.
        )

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
    FetchContent_Populate(ftxui)
    add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# ------------------------------------------------------------------------------

project(Final_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Final_Project main.cpp textprocessors.h textprocessors.cpp Tui.cpp Tui.h)

target_link_libraries(Final_Project
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
)

set_target_properties(Final_Project PROPERTIES CXX_STANDARD 17)