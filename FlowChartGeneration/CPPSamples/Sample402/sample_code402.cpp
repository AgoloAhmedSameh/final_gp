#include <iostream>
#include <regex>
#include <string>

bool is_valid_URL(const std::string& str) {
    std::string regex = R"(((http|https)://)(www\.)?[a-zA-Z0-9@:%._\+~#?&//=]{2,256}\.[a-z]{2,6}\b([-a-zA-Z0-9@:%._\+~#?&//=]*))";
    std::regex p(regex);
    if (str.empty()) {
        return false;
    }
    return std::regex_search(str, p);
}
