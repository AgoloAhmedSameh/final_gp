#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>

std::string snake_to_camel(const std::string& word) {
    std::string result;
    std::istringstream iss(word);
    std::string token;

    while (std::getline(iss, token, '_')) {
        if (!result.empty()) {
            result += toupper(token[0]);
        } else {
            result += token;
        }
        result += token.substr(1);
    }

    return result;
}
