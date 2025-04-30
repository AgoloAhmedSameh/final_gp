#include <vector>
#include <algorithm>
#include <limits>

std::pair<int, int> max_sum(const std::vector<int>& arr, int n) {
    std::vector<int> MSIBS(arr);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && MSIBS[i] < MSIBS[j] + arr[i]) {
                MSIBS[i] = MSIBS[j] + arr[i];
            }
        }
    }
    
    std::vector<int> MSDBS(arr);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (arr[n - i] > arr[n - j] && MSDBS[n - i] < MSDBS[n - j] + arr[n - i]) {
                MSDBS[n - i] = MSDBS[n - j] + arr[n - i];
            }
        }
    }
    
    int max_sum = std::numeric_limits<int>::min();
    for (size_t i = 0; i < n; ++i) {
        max_sum = std::max(max_sum, MSIBS[i] + MSDBS[n - i - 1] - arr[i]);
    }
    
    return {max_sum, 0}; // Returning a dummy second value, as the original code does not specify a second return value.
}
