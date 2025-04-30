#include <iostream>
#include <string>
#include <regex>

std::tuple<int, int, std::string> find_adverb_position(const std::string& text) {
    std::regex pattern(R"(\w+ly)");
    std::smatch match;
    if (std::regex_search(text, match, pattern)) {
        return std::make_tuple(match.position(), match.position() + match.length(), match.str());
    }
    return std::make_tuple(-1, -1, "");
}
