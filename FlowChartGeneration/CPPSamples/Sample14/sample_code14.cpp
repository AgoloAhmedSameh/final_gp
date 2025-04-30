#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::pair<std::vector<std::string>, std::string> split_lowerstring(const std::string& text) {
    std::regex pattern("[a-z][^a-z]*");
    std::sregex_iterator it(text.begin(), text.end(), pattern);
    std::sregex_iterator end;

    std::vector<std::string> result;
    while (it != end) {
        result.push_back(it->str());
        ++it;
    }
    return {result, ""}; // returning an empty string as the second part of the pair
}
