#include <iostream>
#include <string>
#include <algorithm>

std::string remove_vowels(const std::string& text) {
    std::string result;
    for (char s : text) {
        char lower_s = std::tolower(s);
        if (lower_s != 'a' && lower_s != 'e' && lower_s != 'i' && lower_s != 'o' && lower_s != 'u') {
            result += s;
        }
    }
    return result;
}
