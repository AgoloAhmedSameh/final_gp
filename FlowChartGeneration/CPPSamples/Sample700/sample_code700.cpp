#include <vector>

int equilibrium_index(const std::vector<int>& arr) {
    int total_sum = 0;
    for (int num : arr) {
        total_sum += num;
    }
    int left_sum = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
        total_sum -= arr[i];
        if (left_sum == total_sum) {
            return i;
        }
        left_sum += arr[i];
    }
    return -1;
}
