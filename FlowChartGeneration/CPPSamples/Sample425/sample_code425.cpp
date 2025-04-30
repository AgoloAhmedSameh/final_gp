#include <vector>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> filter_oddnumbers(const std::vector<int>& nums) {
    std::vector<int> odd_nums;
    std::copy_if(nums.begin(), nums.end(), std::back_inserter(odd_nums), [](int x) { return x % 2 != 0; });
    return {odd_nums};
}
