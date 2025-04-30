#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

std::pair<std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>> find_combinations(const std::vector<std::pair<int, int>>& test_list) {
    std::vector<std::pair<int, int>> res;
    for (size_t i = 0; i < test_list.size(); ++i) {
        for (size_t j = i + 1; j < test_list.size(); ++j) {
            res.push_back(std::make_pair(test_list[i].first + test_list[j].first, test_list[i].second + test_list[j].second));
        }
    }
    return {res};
}
