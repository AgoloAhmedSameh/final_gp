#include <iostream>
#include <string>
#include <regex>

std::pair<int, std::string> find_adverbs(const std::string& text) {
    std::regex pattern(R"(\w+ly)");
    std::smatch m;
    if (std::regex_search(text, m, pattern)) {
        return {m.position(), m.str()};
    }
    return {-1, ""}; // return invalid position if no match found
}
