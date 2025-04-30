#include <iostream>
#include <regex>
#include <vector>
#include <string>

std::vector<std::string> split_upperstring(const std::string& text) {
    std::regex re("[A-Z][^A-Z]*");
    std::sregex_iterator it(text.begin(), text.end(), re);
    std::sregex_iterator end;
    std::vector<std::string> result;

    while (it != end) {
        result.push_back(it->str());
        ++it;
    }
    return result;
}
