#include <vector>
#include <algorithm>

std::vector<int> pancake_sort(std::vector<int> nums) {
    int arr_len = nums.size();
    while (arr_len > 1) {
        int mi = std::max_element(nums.begin(), nums.begin() + arr_len) - nums.begin();
        std::reverse(nums.begin(), nums.begin() + mi + 1);
        std::reverse(nums.begin(), nums.begin() + arr_len);
        arr_len--;
    }
    return nums;
}
