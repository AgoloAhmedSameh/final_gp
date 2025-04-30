#include <iostream>
#include <regex>
#include <string>

std::string text_match_wordz_middle(const std::string& text) {
    std::regex patterns("\\Bz\\B");
    if (std::regex_search(text, patterns)) {
        return "Found a match!";
    } else {
        return "Not matched!";
    }
}
