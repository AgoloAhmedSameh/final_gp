#include <vector>
#include <algorithm>
#include <utility>

std::pair<std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>> max_similar_indices(const std::vector<std::pair<int, int>>& test_list1, const std::vector<std::pair<int, int>>& test_list2) {
    std::vector<std::pair<int, int>> res;
    for (size_t i = 0; i < test_list1.size(); ++i) {
        res.emplace_back(std::max(test_list1[i].first, test_list2[i].first), std::max(test_list1[i].second, test_list2[i].second));
    }
    return {res};
}
