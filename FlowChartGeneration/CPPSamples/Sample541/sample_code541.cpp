#include <string>
#include <regex>

std::string fill_spaces(const std::string& text) {
    return std::regex_replace(text, std::regex("[ ,.](?!\\w)"), ":");
}
