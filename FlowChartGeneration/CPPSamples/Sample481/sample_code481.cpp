#include <iostream>
#include <regex>
#include <string>

std::string match(const std::string& text) {
    std::regex pattern("[A-Z]+[a-z]+$");
    if (std::regex_search(text, pattern)) {
        return "Yes";
    } else {
        return "No";
    }
}
