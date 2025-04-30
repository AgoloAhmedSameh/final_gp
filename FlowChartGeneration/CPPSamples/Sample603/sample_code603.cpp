#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::string reverse_words(const std::string& s) {
    std::istringstream iss(s);
    std::vector<std::string> words;
    std::string word;

    while (iss >> word) {
        words.push_back(word);
    }

    std::reverse(words.begin(), words.end());

    std::ostringstream oss;
    for (const auto& w : words) {
        oss << w << " ";
    }

    std::string result = oss.str();
    if (!result.empty()) {
        result.pop_back(); // remove the trailing space
    }

    return result;
}
