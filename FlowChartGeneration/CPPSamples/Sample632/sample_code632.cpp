#include <iostream>
#include <vector>

std::pair<int, int> pair_OR_Sum(std::vector<int>& arr, int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = ans + (arr[i] ^ arr[j]);
        }
    }
    return {ans};
}
