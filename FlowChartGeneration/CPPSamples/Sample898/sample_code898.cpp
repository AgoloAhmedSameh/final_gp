#include <vector>

std::pair<bool, bool> check(const std::vector<int>& arr, int n) {
    int g = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i - 1] > 0 && g == 1) {
            return { false, false };
        }
        if (arr[i] - arr[i] < 0) {
            g = 1;
        }
    }
    return { true, true };
}
