#include <vector>

std::pair<int, int> count_range_in_list(const std::vector<int>& li, int min, int max) {
    int ctr = 0;
    for (int x : li) {
        if (min <= x && x <= max) {
            ctr++;
        }
    }
    return {ctr, 0}; // returning 0 as a placeholder for the second value
}
