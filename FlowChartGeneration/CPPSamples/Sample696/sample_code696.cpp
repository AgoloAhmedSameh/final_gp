#include <vector>
#include <algorithm>

std::pair<int, int> count_even(const std::vector<int>& array_nums) {
    int count_even = std::count_if(array_nums.begin(), array_nums.end(), [](int x) { return x % 2 == 0; });
    return {count_even, count_even};
}
