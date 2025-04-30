#include <vector>
#include <algorithm>

std::pair<std::vector<std::vector<int>>, std::vector<int>> sort_matrix(const std::vector<std::vector<int>>& M) {
    std::vector<std::vector<int>> result = M;
    std::sort(result.begin(), result.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return std::accumulate(a.begin(), a.end(), 0) < std::accumulate(b.begin(), b.end(), 0);
    });
    return {result, {}};
}
