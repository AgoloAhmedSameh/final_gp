#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

std::pair<int, int> index_minimum(const std::vector<std::pair<int, int>>& test_list) {
    auto res = *std::min_element(test_list.begin(), test_list.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    return {res.first, res.second};
}
