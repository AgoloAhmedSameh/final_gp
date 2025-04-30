#include <string>

std::pair<std::string> remove_odd(const std::string& str1) {
    std::string str2 = "";
    for (size_t i = 1; i <= str1.length(); ++i) {
        if (i % 2 == 0) {
            str2 += str1[i - 1];
        }
    }
    return {str2};
}
