#include <vector>
#include <unordered_map>
#include <algorithm>

std::unordered_map<int, int> freq_element(const std::vector<std::vector<int>>& nums) {
    std::unordered_map<int, int> result;
    for (const auto& vec : nums) {
        for (const auto& num : vec) {
            result[num]++;
        }
    }
    return result;
}
