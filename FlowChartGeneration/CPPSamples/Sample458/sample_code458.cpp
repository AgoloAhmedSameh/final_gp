#include <iostream>
#include <string>
#include <algorithm>

std::string remove_uppercase(const std::string& str1) {
    std::string result = str1;
    result.erase(std::remove_if(result.begin(), result.end(),
        [](unsigned char c) { return std::isupper(c); }), result.end());
    return result;
}
