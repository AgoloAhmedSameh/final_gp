#include <vector>
#include <unordered_map>
#include <algorithm>

bool is_sorted(const std::vector<int>& lst) {
    std::unordered_map<int, int> count_digit;
    for (int i : lst) {
        count_digit[i] += 1;
    }
    for (const auto& pair : count_digit) {
        if (pair.second > 2) {
            return false;
        }
    }
    for (size_t i = 1; i < lst.size(); ++i) {
        if (lst[i - 1] > lst[i]) {
            return false;
        }
    }
    return true;
}
