#include <vector>

int find_peak_util(const std::vector<int>& arr, int low, int high, int n) {
    int mid = low + (high - low) / 2;
    
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
        (mid == n - 1 || arr[mid + 1] <= arr[mid])) {
        return mid;
    } else if (mid > 0 && arr[mid - 1] > arr[mid]) {
        return find_peak_util(arr, low, mid - 1, n);
    } else {
        return find_peak_util(arr, mid + 1, high, n);
    }
}

int find_peak(const std::vector<int>& arr, int n) {
    return find_peak_util(arr, 0, n - 1, n);
}
