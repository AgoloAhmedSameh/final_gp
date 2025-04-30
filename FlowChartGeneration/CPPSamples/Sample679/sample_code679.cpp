#include <vector>
#include <algorithm>

bool increasing_trend(const std::vector<int>& nums) {
    return std::is_sorted(nums.begin(), nums.end());
}
