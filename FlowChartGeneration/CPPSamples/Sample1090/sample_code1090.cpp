#include <algorithm>
#include <vector>
#include <bitset>
#include <functional>

std::vector<int> sort_array(std::vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    std::stable_sort(arr.begin(), arr.end(), [](int x, int y) {
        return std::bitset<32>(x).count() < std::bitset<32>(y).count();
    });
    return arr;
}
