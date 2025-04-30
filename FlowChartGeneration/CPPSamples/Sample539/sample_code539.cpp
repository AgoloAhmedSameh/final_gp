#include <vector>
#include <algorithm>
#include <limits>

std::pair<int, int> find_Diff(std::vector<int>& arr, int n) {
    std::sort(arr.begin(), arr.end());
    int count = 0, max_count = 0, min_count = n;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            count++;
            continue;
        } else {
            max_count = std::max(max_count, count);
            min_count = std::min(min_count, count);
            count = 0;
        }
    }
    return {max_count - min_count, 0}; // Changed return value to fit C++ style
}
