#include <string>

std::pair<int, int> upper_ctr(const std::string& str) {
    int upper_ctr = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') upper_ctr++;
    }
    return {upper_ctr, 0}; // Returning a pair to match the function signature
}
