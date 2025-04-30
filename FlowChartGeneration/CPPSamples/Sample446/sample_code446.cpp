#include <vector>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> cube_nums(const std::vector<int>& nums) {
    std::vector<int> cube_nums;
    std::transform(nums.begin(), nums.end(), std::back_inserter(cube_nums), [](int x) { return x * x * x; });
    return {cube_nums, {}};
}
