#include <regex>
#include <string>

bool match_num(const std::string& str) {
    std::regex text("^5");
    return std::regex_match(str, text);
}
