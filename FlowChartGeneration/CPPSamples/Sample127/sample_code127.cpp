#include <iostream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> long_words(int n, const std::string& str) {
    std::vector<std::string> word_len;
    std::istringstream iss(str);
    std::string word;
    while (iss >> word) {
        if (word.length() > n) {
            word_len.push_back(word);
        }
    }
    return word_len;
}
