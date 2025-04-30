#include <iostream>
#include <sstream>
#include <vector>
#include <regex>

int is_bored(const std::string& S) {
    std::regex re("[.?!]\\s*");
    std::sregex_token_iterator it(S.begin(), S.end(), re, -1);
    std::sregex_token_iterator end;

    int count = 0;
    for (; it != end; ++it) {
        std::string sentence = *it;
        if (sentence.substr(0, 2) == "I ") {
            count++;
        }
    }
    return count;
}
