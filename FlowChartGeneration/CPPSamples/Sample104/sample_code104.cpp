#include <vector>
#include <numeric>

std::pair<int, int> count(const std::vector<int>& lst) {
    return {std::accumulate(lst.begin(), lst.end(), 0), 0}; // The second value is just a placeholder
}
