#include <vector>

bool even_position(const std::vector<int>& nums) {
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] % 2 != i % 2) {
            return false;
        }
    }
    return true;
}
