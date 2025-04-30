#include <iostream>
#include <string>
#include <regex>

std::string replace_specialchar(const std::string& text) {
    return std::regex_replace(text, std::regex("[ ,.]", ":"), ":");
}
