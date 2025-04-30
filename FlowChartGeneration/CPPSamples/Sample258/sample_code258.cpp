#include <tuple>
#include <vector>
#include <algorithm>

std::pair<std::vector<std::tuple<int, int>>, std::vector<std::tuple<int, int>>> maximize_elements(const std::vector<std::tuple<int, int>>& test_tup1, const std::vector<std::tuple<int, int>>& test_tup2) {
    std::vector<std::tuple<int, int>> res;
    for (size_t i = 0; i < test_tup1.size(); ++i) {
        res.emplace_back(std::max(std::get<0>(test_tup1[i]), std::get<0>(test_tup2[i])), 
                         std::max(std::get<1>(test_tup1[i]), std::get<1>(test_tup2[i])));
    }
    return {res};
}
