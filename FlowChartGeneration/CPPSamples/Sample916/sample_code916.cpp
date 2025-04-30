#include <iostream>
#include <regex>
#include <string>

std::string text_uppercase_lowercase(const std::string& text) {
    std::regex patterns("[A-Z]+[a-z]+$");
    if (std::regex_search(text, patterns)) {
        return "Found a match!";
    } else {
        return "Not matched!";
    }
}
