#include <vector>
#include <algorithm>

bool decreasing_trend(const std::vector<int>& nums) {
    return std::is_sorted(nums.begin(), nums.end(), std::greater<int>());
}
