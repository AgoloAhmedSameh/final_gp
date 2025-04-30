#include <iostream>
#include <vector>
#include <iomanip>

std::pair<double, double> zero_count(const std::vector<int>& nums) {
    int n = nums.size();
    int n1 = 0;
    for (int x : nums) {
        if (x == 0) {
            n1 += 1;
        }
    }
    return {std::round(static_cast<double>(n1) / n * 100) / 100, 0};
}

int main() {
    std::vector<int> nums = {0, 1, 0, 2, 0, 3};
    auto result = zero_count(nums);
    std::cout << std::fixed << std::setprecision(2) << result.first << std::endl;
    return 0;
}
