#include <iostream>
#include <string>
#include <regex>
#include <vector>

std::vector<std::string> find_char(const std::string& text) {
    std::regex word_regex(R"(\b\w{3,5}\b)");
    std::sregex_iterator it(text.begin(), text.end(), word_regex);
    std::sregex_iterator end;

    std::vector<std::string> matches;
    while (it != end) {
        matches.push_back(it->str());
        ++it;
    }

    return matches;
}
