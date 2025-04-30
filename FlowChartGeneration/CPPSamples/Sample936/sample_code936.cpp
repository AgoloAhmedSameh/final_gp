#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

std::pair<char, int> max_char(const std::string &str1) {
    std::unordered_map<char, int> temp;
    for (char c : str1) {
        temp[c]++;
    }
    char max_char = std::max_element(temp.begin(), temp.end(), 
        [](const std::pair<char, int> &a, const std::pair<char, int> &b) {
            return a.second < b.second;
        })->first;
    return {max_char, temp[max_char]};
}
