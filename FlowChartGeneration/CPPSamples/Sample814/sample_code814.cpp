#include <vector>

std::vector<int> sort_by_dnf(std::vector<int>& arr, int n) {
    int low = 0;
    int mid = 0;
    int high = n - 1;
    
    while (mid <= high) {
        if (arr[mid] == 0) {
            std::swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            std::swap(arr[mid], arr[high]);
            high--;
        }
    }
    return arr;
}
