#include <vector>

bool is_Product_Even(std::vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        if ((arr[i] & 1) == 0) {
            return true;
        }
    }
    return false;
}
