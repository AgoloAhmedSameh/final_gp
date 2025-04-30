#include <vector>
#include <numeric>
#include <algorithm>

std::vector<int> max_sum_list(const std::vector<std::vector<int>>& lists) {
    return *std::max_element(lists.begin(), lists.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return std::accumulate(a.begin(), a.end(), 0) < std::accumulate(b.begin(), b.end(), 0);
    });
}
