#include <iostream>
#include <regex>
#include <string>

std::string check_str(const std::string& str) {
    std::regex regex("^[aeiouAEIOU][A-Za-z0-9_]*");
    if (std::regex_search(str, regex)) {
        return "Valid";
    } else {
        return "Invalid";
    }
}
