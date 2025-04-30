#include <string>

std::pair<int, int> count_charac(const std::string& str1) {
    int total = 0;
    for (char i : str1) {
        total = total + 1;
    }
    return std::make_pair(total, total);
}
