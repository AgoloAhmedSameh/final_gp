#include <iostream>
#include <cmath>
#include <bitset>

std::string rounded_avg(int n, int m) {
    if (m < n) {
        return "-1";
    }
    int summation = 0;
    for (int i = n; i <= m; i++) {
        summation += i;
    }
    return std::bitset<32>(std::round(static_cast<double>(summation) / (m - n + 1))).to_string();
}
