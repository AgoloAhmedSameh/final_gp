#include <vector>

std::pair<int, int> kth_element(std::vector<int>& arr, int n, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
    return {arr[k - 1], 0};
}
