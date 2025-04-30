#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, int> min_Ops(std::vector<int>& arr, int n, int k) {
    int max1 = *std::max_element(arr.begin(), arr.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        if ((max1 - arr[i]) % k != 0) {
            return {-1, 0};
        } else {
            res += (max1 - arr[i]) / k;
        }
    }
    return {res, 0}; // Returning res, and a second value to match the original function signature
}
