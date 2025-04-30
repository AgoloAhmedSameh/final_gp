#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> words_string(const std::string& s) {
    if (s.empty()) {
        return {};
    }

    std::string modified_string;
    for (char letter : s) {
        if (letter == ',') {
            modified_string += ' ';
        } else {
            modified_string += letter;
        }
    }

    std::istringstream iss(modified_string);
    std::vector<std::string> result;
    std::string word;
    while (iss >> word) {
        result.push_back(word);
    }

    return result;
}
