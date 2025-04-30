#include <vector>
#include <algorithm>

bool are_Equal(std::vector<int>& arr1, std::vector<int>& arr2, int n, int m) {
    if (n != m) {
        return false;
    }
    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}
