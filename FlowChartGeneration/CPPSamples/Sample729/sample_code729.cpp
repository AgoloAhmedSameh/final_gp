#include <vector>
#include <algorithm>

std::vector<int> consecutive_duplicates(const std::vector<int>& nums) {
    std::vector<int> result;
    if (nums.empty()) return result;

    result.push_back(nums[0]);
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {
            result.push_back(nums[i]);
        }
    }
    return result;
}
