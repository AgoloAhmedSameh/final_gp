#include <vector>
#include <algorithm>
#include <limits>

std::vector<int> pluck(const std::vector<int>& arr) {
    if (arr.empty()) return {};
    std::vector<int> evens;

    for (int x : arr) {
        if (x % 2 == 0) {
            evens.push_back(x);
        }
    }

    if (evens.empty()) return {};
    
    int min_even = *std::min_element(evens.begin(), evens.end());
    int index = std::distance(arr.begin(), std::find(arr.begin(), arr.end(), min_even));
    
    return {min_even, index};
}
