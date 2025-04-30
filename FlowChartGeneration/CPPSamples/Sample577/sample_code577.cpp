#include <vector>
#include <tuple>

std::vector<int> interleave_lists(const std::vector<int>& list1, const std::vector<int>& list2, const std::vector<int>& list3) {
    std::vector<int> result;
    auto size = std::min({list1.size(), list2.size(), list3.size()});
    for (size_t i = 0; i < size; ++i) {
        result.push_back(list1[i]);
        result.push_back(list2[i]);
        result.push_back(list3[i]);
    }
    return result;
}
