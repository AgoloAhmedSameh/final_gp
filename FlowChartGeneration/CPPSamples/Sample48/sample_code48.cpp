#include <vector>

std::vector<int> specified_element(const std::vector<std::vector<int>>& nums, int N) {
    std::vector<int> result;
    for (const auto& i : nums) {
        result.push_back(i[N]);
    }
    return result;
}
