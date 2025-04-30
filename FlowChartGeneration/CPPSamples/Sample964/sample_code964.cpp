#include <iostream>
#include <string>
#include <regex>
#include <cctype>
#include <algorithm>

std::string camel_to_snake(const std::string& text) {
    std::string str1 = std::regex_replace(text, std::regex("(.)([A-Z][a-z]+)"), "$1_$2");
    std::string result = std::regex_replace(str1, std::regex("([a-z0-9])([A-Z])"), "$1_$2");
    
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return std::tolower(c); });
    return result;
}

int main() {
    std::string text = "CamelCaseText"; // Example usage
    std::cout << camel_to_snake(text) << std::endl;
    return 0;
}
