#include <vector>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> square_nums(const std::vector<int>& nums) {
    std::vector<int> squared_nums(nums.size());
    std::transform(nums.begin(), nums.end(), squared_nums.begin(), [](int x) { return x * x; });
    return {squared_nums};
}
