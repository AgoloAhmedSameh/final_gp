#include <vector>
#include <algorithm>
#include <numeric>

std::pair<int, int> sum_positivenum(const std::vector<int>& nums) {
    std::vector<int> sum_positivenum;
    std::copy_if(nums.begin(), nums.end(), std::back_inserter(sum_positivenum), [](int num) { return num > 0; });
    return {std::accumulate(sum_positivenum.begin(), sum_positivenum.end(), 0), 0};
}
