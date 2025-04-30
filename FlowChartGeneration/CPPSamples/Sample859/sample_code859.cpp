#include <iostream>
#include <regex>
#include <string>

std::string check_alphanumeric(const std::string& str) {
    std::regex regex("[a-zA-Z0-9]$");
    if (std::regex_search(str, regex)) {
        return "Accept";
    } else {
        return "Discard";
    }
}
