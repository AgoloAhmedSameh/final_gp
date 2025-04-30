#include <vector>
#include <tuple>

std::vector<std::vector<std::tuple<int>>> add_K_element(const std::vector<std::vector<int>>& test_list, int K) {
    std::vector<std::vector<std::tuple<int>>> res;
    for (const auto& sub : test_list) {
        std::vector<std::tuple<int>> temp;
        for (const auto& j : sub) {
            temp.push_back(std::make_tuple(j + K));
        }
        res.push_back(temp);
    }
    return res;
}
