#include <iostream>
#include <vector>
#include <string>

std::string check_last(std::vector<int> arr, int n, int p) {
    int _sum = 0;
    for (int i = 0; i < n; i++) {
        _sum = _sum + arr[i];
    }
    if (p == 1) {
        if (_sum % 2 == 0) {
            return "ODD";
        } else {
            return "EVEN";
        }
    }
    return "EVEN";
}
