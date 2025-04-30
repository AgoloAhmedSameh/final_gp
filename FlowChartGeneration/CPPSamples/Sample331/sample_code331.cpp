#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<char, int> char_frequency(const std::string& str1) {
    std::unordered_map<char, int> dict;
    for (char n : str1) {
        dict[n]++;
    }
    return dict;
}
