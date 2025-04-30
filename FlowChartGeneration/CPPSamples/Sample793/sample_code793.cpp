#include <iostream>
#include <regex>
#include <string>

std::string text_starta_endb(const std::string& text) {
    std::regex patterns("a.*?b$");
    if (std::regex_search(text, patterns)) {
        return "Found a match!";
    } else {
        return "Not matched!";
    }
}
