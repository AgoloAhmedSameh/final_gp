#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

std::vector<std::pair<int, int>> sort_counter(const std::unordered_map<int, int>& dict1) {
    std::vector<std::pair<int, int>> count_vector(dict1.begin(), dict1.end());
    std::sort(count_vector.begin(), count_vector.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    return count_vector;
}
