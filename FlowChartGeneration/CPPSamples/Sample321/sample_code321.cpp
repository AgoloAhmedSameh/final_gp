#include <vector>
#include <algorithm>

std::pair<std::vector<int>, int> position_min(const std::vector<int>& list1) {
    int min_val = *std::min_element(list1.begin(), list1.end());
    std::vector<int> min_result;
    for (size_t i = 0; i < list1.size(); ++i) {
        if (list1[i] == min_val) {
            min_result.push_back(i);
        }
    }
    return {min_result, min_val};
}
