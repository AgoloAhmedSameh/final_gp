#include <vector>
#include <algorithm>

std::vector<int> ntimes_list(const std::vector<int>& nums, int n) {
    std::vector<int> result(nums.size());
    std::transform(nums.begin(), nums.end(), result.begin(), [n](int x) { return n * x; });
    return result;
}
