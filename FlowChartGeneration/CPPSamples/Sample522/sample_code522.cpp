#include <iostream>
#include <string>
#include <vector>
#include <cctype>

std::vector<std::string> check_string(const std::string& str1) {
    std::vector<std::string> result;
    
    if (std::none_of(str1.begin(), str1.end(), [](char x) { return std::isupper(x); })) {
        result.push_back("String must have 1 upper case character.");
    }
    if (std::none_of(str1.begin(), str1.end(), [](char x) { return std::islower(x); })) {
        result.push_back("String must have 1 lower case character.");
    }
    if (std::none_of(str1.begin(), str1.end(), [](char x) { return std::isdigit(x); })) {
        result.push_back("String must have 1 number.");
    }
    if (str1.length() < 7) {
        result.push_back("String length should be at least 8.");
    }

    if (result.empty()) {
        result.push_back("Valid string.");
    }

    return result;
}
