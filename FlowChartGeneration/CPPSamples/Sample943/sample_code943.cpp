#include <iostream>
#include <regex>
#include <string>

std::pair<int, int> num_position(const std::string& text) {
    std::regex pattern(R"(\d+)");
    std::smatch match;
    if (std::regex_search(text, match, pattern)) {
        return {match.position(), match.length()};
    }
    return {-1, -1}; // Return an invalid position if no match is found
}
