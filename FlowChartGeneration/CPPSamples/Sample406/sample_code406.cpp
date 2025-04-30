#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool rearrange_bigger(int n) {
    std::string str_n = std::to_string(n);
    std::vector<char> nums(str_n.begin(), str_n.end());
    for (int i = nums.size() - 2; i >= 0; --i) {
        if (nums[i] < nums[i + 1]) {
            std::vector<char> z(nums.begin() + i, nums.end());
            char y = *std::min_element(z.begin(), z.end(), [&](char a, char b) { return a > z[0] && a < b; });
            z.erase(std::remove(z.begin(), z.end(), y), z.end());
            std::sort(z.begin(), z.end());
            nums.erase(nums.begin() + i, nums.end());
            nums.push_back(y);
            nums.insert(nums.end(), z.begin(), z.end());
            return std::stoi(std::string(nums.begin(), nums.end()));
        }
    }
    return false;
}
