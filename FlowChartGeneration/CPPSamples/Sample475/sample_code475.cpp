#include <vector>
#include <algorithm>

std::pair<int, int> big_sum(const std::vector<int>& nums) {
    int sum = *std::max_element(nums.begin(), nums.end()) + *std::min_element(nums.begin(), nums.end());
    return {sum, sum}; // Returns a pair, the second value is the sum again as in the original function
}
