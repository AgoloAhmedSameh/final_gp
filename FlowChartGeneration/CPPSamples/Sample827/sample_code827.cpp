#include <iostream>
#include <string>
#include <tuple>

std::tuple<int, int, int> count_alpha_dig_spl(const std::string& str) {
    int alphabets = 0, digits = 0, special = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            alphabets++;
        } else if (isdigit(str[i])) {
            digits++;
        } else {
            special++;
        }
    }
    return std::make_tuple(alphabets, digits, special);
}
