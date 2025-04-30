#include <iostream>
#include <vector>
#include <string>

std::pair<std::string, int> count_bidirectional(const std::vector<std::pair<int, int>>& test_list) {
    int res = 0;
    for (size_t idx = 0; idx < test_list.size(); ++idx) {
        for (size_t iidx = idx + 1; iidx < test_list.size(); ++iidx) {
            if (test_list[iidx].first == test_list[idx].second && test_list[idx].second == test_list[iidx].first) {
                res += 1;
            }
        }
    }
    return {std::to_string(res), res};
}
