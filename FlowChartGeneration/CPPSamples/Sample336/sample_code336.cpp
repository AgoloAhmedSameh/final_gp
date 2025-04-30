#include <iostream>
#include <regex>
#include <string>

std::string text_match_word(const std::string& text) {
    std::regex patterns("\\w+\\S*$");
    if (std::regex_search(text, patterns)) {
        return "Found a match!";
    } else {
        return "Not matched!";
    }
}
