#include <vector>
#include <algorithm>

std::pair<int, int> sum_negativenum(const std::vector<int>& nums) {
    std::vector<int> negative_nums;
    std::copy_if(nums.begin(), nums.end(), std::back_inserter(negative_nums), [](int num) { return num < 0; });
    int sum = std::accumulate(negative_nums.begin(), negative_nums.end(), 0);
    return {sum, 0}; // Returning 0 as a placeholder for the second return value in the original Python code
}
