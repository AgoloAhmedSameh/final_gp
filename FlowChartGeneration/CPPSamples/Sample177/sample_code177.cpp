#include <iostream>
#include <regex>
#include <string>
#include <vector>

std::string string_literals(const std::vector<std::string>& patterns, const std::string& text) {
    for (const auto& pattern : patterns) {
        if (std::regex_search(text, std::regex(pattern))) {
            return "Matched!";
        } else {
            return "Not Matched!";
        }
    }
    return "Not Matched!";
}
