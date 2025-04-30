#include <string>

std::pair<int, int> count(const std::string& s, char c) {
    int res = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] == c) {
            res = res + 1;
        }
    }
    return {res, 0}; // Returning 0 as the second value since it's not defined in Python code
}
