#include <string>

std::pair<int, int> count_char_position(const std::string& str1) {
    int count_chars = 0;
    for (size_t i = 0; i < str1.length(); ++i) {
        if ((i == static_cast<int>(str1[i]) - static_cast<int>('A')) || 
            (i == static_cast<int>(str1[i]) - static_cast<int>('a'))) {
            count_chars += 1;
        }
    }
    return {count_chars, 0};
}
