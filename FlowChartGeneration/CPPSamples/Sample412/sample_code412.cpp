#include <vector>

std::vector<int> extract_nth_element(const std::vector<std::vector<int>>& list1, int n) {
    std::vector<int> result;
    for (const auto& x : list1) {
        result.push_back(x[n]);
    }
    return result;
}
