#include <vector>
#include <algorithm>

std::pair<int, int> max_sum_increasing_subsequence(const std::vector<int>& arr, int n) {
    int max = 0;
    std::vector<int> msis(n, 0);
    for (int i = 0; i < n; ++i) {
        msis[i] = arr[i];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i]) {
                msis[i] = msis[j] + arr[i];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (max < msis[i]) {
            max = msis[i];
        }
    }
    return {max, 0}; // The second value can be adjusted or removed as needed
}
