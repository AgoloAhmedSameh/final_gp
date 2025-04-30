#include <iostream>
#include <regex>
#include <string>

std::string text_match_three(const std::string& text) {
    std::regex patterns("ab{3}?");
    if (std::regex_search(text, patterns)) {
        return "Found a match!";
    } else {
        return "Not matched!";
    }
}
