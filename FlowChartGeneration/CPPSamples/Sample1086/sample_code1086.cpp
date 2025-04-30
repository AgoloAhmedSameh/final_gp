#include <string>
#include <algorithm>

std::pair<std::string, bool> reverse_delete(const std::string &s, const std::string &c) {
    std::string result;
    for (char char_s : s) {
        if (c.find(char_s) == std::string::npos) {
            result += char_s;
        }
    }
    std::string reversed = result;
    std::reverse(reversed.begin(), reversed.end());
    return {result, result == reversed};
}
