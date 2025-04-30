#include <vector>

std::pair<int, int> find_remainder(const std::vector<int>& arr, int lens, int n) {
    int mul = 1;
    for (int i = 0; i < lens; ++i) {
        mul = (mul * (arr[i] % n)) % n;
    }
    return {mul % n, 0}; // Assuming the second return value is not needed, since it's not used in the Python code
}
