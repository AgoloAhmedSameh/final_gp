#include <vector>
#include <algorithm>

std::vector<int> add_list(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::vector<int> result(nums1.size());
    std::transform(nums1.begin(), nums1.end(), nums2.begin(), result.begin(), std::plus<int>());
    return result;
}
