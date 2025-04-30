#include <vector>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> div_of_nums(const std::vector<int>& nums, int m, int n) {
    std::vector<int> result;
    std::copy_if(nums.begin(), nums.end(), std::back_inserter(result), [m, n](int x) {
        return (x % m == 0 && x % n == 0);
    });
    return {result};
}
