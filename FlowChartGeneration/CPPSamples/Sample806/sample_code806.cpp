#include <vector>

std::pair<int, int> first_odd(const std::vector<int>& nums) {
    for (int el : nums) {
        if (el % 2 != 0) {
            return {el, 1};
        }
    }
    return {-1, 1};
}
