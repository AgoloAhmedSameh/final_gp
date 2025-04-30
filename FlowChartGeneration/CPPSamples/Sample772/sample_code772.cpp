#include <iostream>
#include <string>
#include <regex>

std::tuple<std::string, size_t, size_t> occurance_substring(const std::string& text, const std::string& pattern) {
    std::regex re(pattern);
    std::smatch match;
    if (std::regex_search(text, match, re)) {
        size_t s = match.position();
        size_t e = s + match.length();
        return std::make_tuple(match.str(), s, e);
    }
    return std::make_tuple("", 0, 0); // Return empty tuple if no match found
}
