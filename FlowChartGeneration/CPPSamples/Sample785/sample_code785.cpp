#include <vector>
#include <algorithm>

std::pair<int, int> right_insertion(const std::vector<int>& a, int x) {
    int i = std::upper_bound(a.begin(), a.end(), x) - a.begin();
    return {i, 0};
}
