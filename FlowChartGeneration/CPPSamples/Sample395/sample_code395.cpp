#include <iostream>
#include <regex>
#include <string>

std::string check_char(const std::string& str) {
    std::regex regex("^[a-z]$|^([a-z]).*\\1$");
    if (std::regex_search(str, regex)) {
        return "Valid";
    } else {
        return "Invalid";
    }
}
