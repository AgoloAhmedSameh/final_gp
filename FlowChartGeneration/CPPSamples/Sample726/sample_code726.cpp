#include <regex>
#include <string>

std::pair<std::string, std::string> remove_char(const std::string &S) {
    std::regex re("[\\W_]+");
    std::string result = std::regex_replace(S, re, "");
    return {result, ""}; // returning an empty string as the second value
}
