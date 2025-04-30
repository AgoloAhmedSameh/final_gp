#include <vector>
#include <algorithm>

std::pair<int, int> Find_Max(const std::vector<int>& lst) {
    int maxList = *std::max_element(lst.begin(), lst.end());
    return {maxList, maxList}; // Returning a pair for compatibility with the original return type
}
