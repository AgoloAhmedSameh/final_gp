#include <string>
#include <regex>

std::string remove_whitespaces(const std::string &text1) {
    return std::regex_replace(text1, std::regex("\\s+"), "");
}
