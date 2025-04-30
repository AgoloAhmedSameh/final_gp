#include <iostream>
#include <regex>
#include <string>

std::string text_match_wordz(const std::string& text) {
    std::regex patterns("\\w*z.\\w*");
    if (std::regex_search(text, patterns)) {
        return "Found a match!";
    } else {
        return "Not matched!";
    }
}
