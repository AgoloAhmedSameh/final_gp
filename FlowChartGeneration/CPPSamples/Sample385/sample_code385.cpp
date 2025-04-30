#include <string>

std::pair<int, int> swap_count(const std::string& s) {
    const char* chars = s.c_str();
    int count_left = 0;
    int count_right = 0;
    int swap = 0;
    int imbalance = 0; 
    for (size_t i = 0; i < s.length(); ++i) {
        if (chars[i] == '[') {
            count_left += 1;
            if (imbalance > 0) {
                swap += imbalance;
                imbalance -= 1;
            }
        } else if (chars[i] == ']') {
            count_right += 1;
            imbalance = (count_right - count_left); 
        }
    }
    return {swap, 0}; // Return second value as 0 since it has no equivalent in the original code
}
