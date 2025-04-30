#include <string>
#include <regex>

std::string remove_lowercase(const std::string& str1) {
    std::regex lower_case_regex("[a-z]");
    std::string result = std::regex_replace(str1, lower_case_regex, "");
    return result;
}
