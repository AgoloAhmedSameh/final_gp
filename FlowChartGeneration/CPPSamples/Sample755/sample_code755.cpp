#include <iostream>
#include <regex>
#include <string>

std::string text_match_zero_one(const std::string& text) {
    std::regex patterns("ab?");
    if (std::regex_search(text, patterns)) {
        return "Found a match!";
    } else {
        return "Not matched!";
    }
}
