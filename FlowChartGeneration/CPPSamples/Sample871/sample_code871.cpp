#include <vector>
#include <algorithm>

bool check_subset(const std::vector<int>& list1, const std::vector<int>& list2) {
    return std::all_of(list2.begin(), list2.end(), [&](int x) { return std::find(list1.begin(), list1.end(), x) != list1.end(); });
}
