#include <string>

std::pair<int, int> count_char(const std::string& str, char ch) {
    int count = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == ch) {
            count++;
        }
    }
    return {count, 0};
}
