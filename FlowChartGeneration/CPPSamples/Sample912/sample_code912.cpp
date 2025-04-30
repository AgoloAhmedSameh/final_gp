#include <regex>
#include <string>

bool end_num(const std::string& str) {
    std::regex text(".*[0-9]$");
    return std::regex_match(str, text);
}
