#include <algorithm>
#include <vector>
#include <limits>

std::pair<long long, long long> find_Min_Diff(std::vector<long long>& arr, int n) {
    std::sort(arr.begin(), arr.end());
    long long diff = std::numeric_limits<long long>::max();
    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] - arr[i] < diff) {
            diff = arr[i + 1] - arr[i];
        }
    }
    return {diff, diff};
}
