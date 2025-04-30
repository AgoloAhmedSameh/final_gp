#include <iostream>
#include <regex>
#include <string>
#include <cctype>

std::string camel_to_snake(const std::string& text) {
    std::string str1 = std::regex_replace(text, std::regex("(.)([A-Z][a-z]+)"), "$1_$2");
    return std::regex_replace(str1, std::regex("([a-z0-9])([A-Z])"), "$1_$2");
}

int main() {
    std::string text = "ExampleCamelCaseString";
    std::cout << camel_to_snake(text) << std::endl;
    return 0;
}
