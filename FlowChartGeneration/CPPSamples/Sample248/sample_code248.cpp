#include <vector>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> intersection_array(std::vector<int>& array_nums1, std::vector<int>& array_nums2) {
    std::vector<int> result;
    std::copy_if(array_nums2.begin(), array_nums2.end(), std::back_inserter(result),
                 [&array_nums1](int x) { return std::find(array_nums1.begin(), array_nums1.end(), x) != array_nums1.end(); });
    return {result};
}
