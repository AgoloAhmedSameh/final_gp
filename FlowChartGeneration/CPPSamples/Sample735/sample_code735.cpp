#include <vector>
#include <algorithm>

std::pair<int, int> left_insertion(const std::vector<int>& a, int x) {
    int i = std::lower_bound(a.begin(), a.end(), x) - a.begin();
    return {i, 0}; // Return 0 as a placeholder for the second value since it's not used
}
