#include <vector>
#include <cmath>
#include <numeric>

std::pair<int, int> round_and_sum(const std::vector<double>& list1) {
    int length = list1.size();
    int round_and_sum = std::accumulate(list1.begin(), list1.end(), 0, [](int sum, double value) {
        return sum + std::round(value);
    }) * length;
    return {round_and_sum, round_and_sum};
}
