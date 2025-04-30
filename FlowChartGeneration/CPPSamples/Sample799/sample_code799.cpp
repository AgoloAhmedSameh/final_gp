#include <iostream>
#include <string>
#include <algorithm>

std::string remove_all_spaces(const std::string& text) {
    std::string result = text;
    result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
    return result;
}
