#include <vector>
#include <tuple>

std::vector<std::tuple<int, int>> join_tuples(const std::vector<std::vector<int>>& test_list) {
    std::vector<std::vector<int>> res;
    for (const auto& sub : test_list) {
        if (!res.empty() && res.back()[0] == sub[0]) {
            res.back().insert(res.back().end(), sub.begin() + 1, sub.end());
        } else {
            res.push_back(sub);
        }
    }
    std::vector<std::tuple<int, int>> result;
    for (const auto& r : res) {
        result.emplace_back(std::make_tuple(r[0], r[1])); // Adjust tuple type as needed
    }
    return result;
}
