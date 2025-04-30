#include <vector>

std::pair<std::vector<int>, std::vector<int>> nth_items(const std::vector<int>& list, int n) {
    std::vector<int> result;
    for (size_t i = 0; i < list.size(); i += n) {
        result.push_back(list[i]);
    }
    return {result};
}
