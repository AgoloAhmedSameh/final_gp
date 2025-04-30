#include <algorithm>
#include <vector>

std::vector<std::vector<int>> sort_sublists(const std::vector<std::vector<int>>& list1) {
    std::vector<std::vector<int>> result = list1;
    for (auto& sublist : result) {
        std::sort(sublist.begin(), sublist.end());
    }
    return result;
}
