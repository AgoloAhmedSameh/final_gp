#include <string>

std::pair<int, int> string_length(const std::string& str1) {
    int count = 0;
    for (char char : str1) {
        count += 1;
    }
    return {count, 0}; // Assuming the second return value should be 0 as a placeholder
}
