#include <vector>
#include <algorithm>
#include <limits>

std::pair<int, int> maximum_Sum(const std::vector<std::vector<int>>& list1) {
    int maxi = -100000;
    for (const auto& x : list1) {
        int sum = 0;
        for (int y : x) {
            sum += y;
        }
        maxi = std::max(sum, maxi);
    }
    return {maxi};
}
