#include <vector>
#include <tuple>

std::pair<std::vector<std::tuple<int, int>>, std::vector<std::tuple<int, int>>> extract_missing(const std::vector<std::tuple<int, int>>& test_list, int strt_val, int stop_val) {
    std::vector<std::tuple<int, int>> res;
    for (const auto& sub : test_list) {
        if (std::get<0>(sub) > strt_val) {
            res.emplace_back(strt_val, std::get<0>(sub));
            strt_val = std::get<1>(sub);
        }
    }
    if (strt_val < stop_val) {
        res.emplace_back(strt_val, stop_val);
    }
    return {res};
}
