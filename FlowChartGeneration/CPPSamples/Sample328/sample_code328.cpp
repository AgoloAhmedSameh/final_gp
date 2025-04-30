#include <vector>

std::pair<int, int> neg_count(const std::vector<int>& list) {
    int neg_count = 0;
    for (int num : list) {
        if (num <= 0) {
            neg_count += 1;
        }
    }
    return {neg_count, 0}; // Added 0 to match the return type with a pair
}
