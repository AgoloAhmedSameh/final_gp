#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

std::pair<int, int> max_occurrences(const std::vector<int>& nums) {
    std::unordered_map<int, int> dict;
    for (int i : nums) {
        dict[i] += 1;
    }
    auto result = std::max_element(dict.begin(), dict.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    return *result;
}
