#include <vector>
#include <algorithm>

std::pair<int, int> Find_Min(const std::vector<int>& lst) {
    int minList = *std::min_element(lst.begin(), lst.end());
    return {minList, 0}; // Return a pair; second value is placeholder (0)
}
