#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

std::pair<int, int> min_product_tuple(const std::vector<std::pair<int, int>>& list1) {
    int result_min = std::abs(list1[0].first * list1[0].second);
    for (const auto& p : list1) {
        result_min = std::min(result_min, std::abs(p.first * p.second));
    }
    return {result_min, result_min};
}
