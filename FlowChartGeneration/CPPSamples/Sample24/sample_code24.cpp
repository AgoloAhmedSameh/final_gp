#include <iostream>
#include <vector>
#include <algorithm>

int find_Product(std::vector<int>& arr, int n) {
    std::sort(arr.begin(), arr.end());
    int prod = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i - 1] != arr[i]) {
            prod = prod * arr[i];
        }
    }
    return prod;
}
