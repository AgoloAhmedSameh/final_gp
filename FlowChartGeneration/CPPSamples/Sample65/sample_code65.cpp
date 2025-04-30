#include <vector>

std::pair<int, int> pos_count(const std::vector<int>& list) {
    int pos_count = 0;
    for (int num : list) {
        if (num >= 0) {
            pos_count += 1;
        }
    }
    return {pos_count, 0}; // Returning a pair with second value as 0 to match the return type
}
