#include <iostream>
#include <string>

std::pair<int, char> ascii_value_string(const std::string& str1) {
    for (size_t i = 0; i < str1.length(); ++i) {
        return std::make_pair(static_cast<int>(str1[i]), str1[i]);
    }
    return std::make_pair(-1, '\0'); // return -1 and null character if the string is empty
}
