#include <iostream>
#include <regex>
#include <string>

std::pair<std::string, std::string> replace(const std::string& str, char ch) {
    std::string pattern = std::string(1, ch) + "{2,}";
    std::regex re(pattern);
    std::string result = std::regex_replace(str, re, std::string(1, ch));
    return {result, {}};
}
