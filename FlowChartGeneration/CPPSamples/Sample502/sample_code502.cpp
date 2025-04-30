#include <vector>

std::pair<std::vector<int>, std::vector<int>> add_consecutive_nums(const std::vector<int>& nums) {
    std::vector<int> result;
    for (size_t i = 0; i < nums.size() - 1; ++i) {
        result.push_back(nums[i] + nums[i + 1]);
    }
    return {result};
}
