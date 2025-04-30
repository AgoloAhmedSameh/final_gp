#include <vector>
#include <tuple>

std::vector<std::vector<int>> adjac(const std::vector<int>& ele, std::vector<int> sub = {}) {
    std::vector<std::vector<int>> result;
    if (ele.empty()) {
        result.push_back(sub);
    } else {
        for (int j = ele[0] - 1; j <= ele[0] + 1; ++j) {
            auto sub_result = adjac(std::vector<int>(ele.begin() + 1, ele.end()), sub);
            for (auto& idx : sub_result) {
                idx.push_back(j);
                result.push_back(idx);
            }
        }
    }
    return result;
}

std::tuple<std::vector<std::vector<int>>> get_coordinates(const std::vector<int>& test_tup) {
    auto res = adjac(test_tup);
    return {res};
}
