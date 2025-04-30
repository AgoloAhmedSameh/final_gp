#include <vector>
#include <algorithm>

std::vector<int> mul_list(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::vector<int> result;
    std::transform(nums1.begin(), nums1.end(), nums2.begin(), std::back_inserter(result), std::multiplies<int>());
    return result;
}
