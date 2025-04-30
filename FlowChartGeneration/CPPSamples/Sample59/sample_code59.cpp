#include <vector>
#include <algorithm>
#include <cmath>

std::pair<int, int> max_len_sub(const std::vector<int>& arr, int n) {
    std::vector<int> mls(n, 1);
    int max = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (std::abs(arr[i] - arr[j]) <= 1 && mls[i] < mls[j] + 1) {
                mls[i] = mls[j] + 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (max < mls[i]) {
            max = mls[i];
        }
    }

    return {max, 0}; // Returning 0 as a placeholder for the second value
}
