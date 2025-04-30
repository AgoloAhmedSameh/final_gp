#include <vector>

int sum_Range_list(const std::vector<int>& nums, int m, int n) {
    int sum_range = 0;
    for (int i = m; i <= n; ++i) {
        sum_range += nums[i];
    }
    return sum_range;
}
