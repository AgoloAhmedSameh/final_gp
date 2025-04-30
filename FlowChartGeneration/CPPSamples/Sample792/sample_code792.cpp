#include <vector>

std::pair<int, int> last(const std::vector<int>& arr, int x, int n) {
    int low = 0;
    int high = n - 1;
    int res = -1;  
    while (low <= high) {
        int mid = (low + high) / 2; 
        if (arr[mid] > x) {
            high = mid - 1;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            res = mid;
            low = mid + 1;
        }
    }
    return {res, -1}; // Return the result and a placeholder for the second value
}
