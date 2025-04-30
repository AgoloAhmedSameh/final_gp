#include <algorithm>
#include <vector>

std::pair<int, int> find_Sum(std::vector<int>& arr, int n) {
    std::sort(arr.begin(), arr.end());
    int sum = arr[0];
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] != arr[i + 1]) {
            sum += arr[i + 1];
        }
    }
    return {sum, 0}; // Returning 0 as a placeholder for the second value, to match the original return type.
}
