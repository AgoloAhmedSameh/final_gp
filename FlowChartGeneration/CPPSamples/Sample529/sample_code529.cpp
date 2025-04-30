#include <iostream>
#include <vector>
#include <iomanip>

std::pair<double, double> negative_count(const std::vector<int>& nums) {
    int n = nums.size();
    int n1 = 0;
    for (int x : nums) {
        if (x < 0) {
            n1 += 1;
        }
    }
    return {std::round(static_cast<double>(n1) / n * 100.0) / 100.0, static_cast<double>(n1) / n};
}
