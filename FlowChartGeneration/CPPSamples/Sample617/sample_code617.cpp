#include <vector>
#include <functional>

std::vector<double> div_list(const std::vector<double>& nums1, const std::vector<double>& nums2) {
    std::vector<double> result;
    for (size_t i = 0; i < nums1.size(); ++i) {
        result.push_back(nums1[i] / nums2[i]);
    }
    return result;
}
