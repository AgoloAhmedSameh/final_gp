#include <vector>

std::pair<bool, bool> greater_specificnum(const std::vector<int>& list, int num) {
    bool greater_specificnum = std::all_of(list.begin(), list.end(), [num](int x) { return x >= num; });
    return {greater_specificnum, greater_specificnum};
}
