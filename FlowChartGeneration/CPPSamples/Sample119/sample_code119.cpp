#include <vector>
#include <algorithm>
#include <cmath>

std::pair<int, int> max_product_tuple(const std::vector<std::pair<int, int>>& list1) {
    int result_max = 0;
    for (const auto& p : list1) {
        result_max = std::max(result_max, std::abs(p.first * p.second));
    }
    return {result_max, 0}; // Returning 0 as a placeholder for the second value.
}
