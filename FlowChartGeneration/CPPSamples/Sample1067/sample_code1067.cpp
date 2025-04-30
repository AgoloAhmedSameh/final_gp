#include <iostream>
#include <string>
#include <unordered_map>

std::string encode(const std::string& message) {
    std::string vowels = "aeiouAEIOU";
    std::unordered_map<char, char> vowels_replace;

    for (char i : vowels) {
        vowels_replace[i] = i + 2;
    }

    std::string swapped_message;
    for (char i : message) {
        if (isupper(i)) {
            swapped_message += tolower(i);
        } else {
            swapped_message += toupper(i);
        }
    }

    std::string result;
    for (char i : swapped_message) {
        if (vowels_replace.find(i) != vowels_replace.end()) {
            result += vowels_replace[i];
        } else {
            result += i;
        }
    }

    return result;
}
