#include <algorithm>
#include <vector>

std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> sort_sublists(std::vector<std::vector<int>>& list1) {
    std::sort(list1.begin(), list1.end());
    std::sort(list1.begin(), list1.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a.size() < b.size();
    });
    return {list1, list1};
}
