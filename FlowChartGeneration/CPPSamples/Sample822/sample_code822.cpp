#include <iostream>
#include <string>
#include <regex>

std::string check_substring(const std::string& str, const std::string& sample) {
    if (str.find(sample) != std::string::npos) {
        std::string y = "^" + sample; 
        std::regex pattern(y);
        if (std::regex_search(str, pattern)) {
            return "string starts with the given substring";
        } else {
            return "string doesn't start with the given substring";
        }
    } else {
        return "entered string isn't a substring";
    }
}
