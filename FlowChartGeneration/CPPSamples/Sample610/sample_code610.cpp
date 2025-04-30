#include <vector>
#include <algorithm>

std::pair<int, int> max_of_nth(const std::vector<std::vector<int>>& test_list, int N) {
    std::vector<int> values;
    for (const auto& sub : test_list) {
        values.push_back(sub[N]);
    }
    int res = *std::max_element(values.begin(), values.end());
    return std::make_pair(res);
}
