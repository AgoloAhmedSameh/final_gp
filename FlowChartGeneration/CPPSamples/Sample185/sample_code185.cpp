#include <iostream>
#include <regex>
#include <string>
#include <vector>

std::string check_literals(const std::string& text, const std::vector<std::string>& patterns) {
    for (const auto& pattern : patterns) {
        if (std::regex_search(text, std::regex(pattern))) {
            return "Matched!";
        } else {
            return "Not Matched!";
        }
    }
    return "Not Matched!";
}
