#include <vector>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> remove_elements(const std::vector<int>& list1, const std::vector<int>& list2) {
    std::vector<int> result;
    for (const auto& x : list1) {
        if (std::find(list2.begin(), list2.end(), x) == list2.end()) {
            result.push_back(x);
        }
    }
    return {result, {}};
}
