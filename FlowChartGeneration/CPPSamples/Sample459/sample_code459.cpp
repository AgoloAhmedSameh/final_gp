#include <vector>
#include <tuple>

std::pair<std::vector<int>, std::vector<int>> Extract(const std::vector<std::vector<int>>& lst) {
    std::vector<int> result;
    for (const auto& item : lst) {
        result.push_back(item[0]);
    }
    return std::make_pair(result);
}
