#include <vector>
#include <algorithm>

std::pair<int, int> first_even(const std::vector<int>& nums) {
    auto it = std::find_if(nums.begin(), nums.end(), [](int el) { return el % 2 == 0; });
    int first_even = (it != nums.end()) ? *it : -1;
    return {first_even, 0}; // Assuming the second value is not relevant as per the original function
}
