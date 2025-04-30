#include <vector>
#include <algorithm>

std::vector<int> rolling_max(const std::vector<int>& numbers) {
    int running_max = -1; // assuming numbers are non-negative, otherwise use std::numeric_limits<int>::min()
    std::vector<int> result;

    for (int n : numbers) {
        if (running_max == -1) { // Check for initial case
            running_max = n;
        } else {
            running_max = std::max(running_max, n);
        }

        result.push_back(running_max);
    }

    return result;
}
