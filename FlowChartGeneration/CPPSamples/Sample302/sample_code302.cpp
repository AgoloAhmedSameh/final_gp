#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

bool solve(const std::vector<int>& a, int n) {
    int mx = INT_MIN;
    for (int j = 1; j < n; j++) {
        if (mx > a[j]) {
            return false;
        }
        mx = std::max(mx, a[j - 1]);
    }
    return true;
}
