#include <vector>
#include <algorithm>
#include <limits>

std::pair<int, int> max_sub_array_sum_repeated(std::vector<int>& a, int n, int k) {
    int max_so_far = std::numeric_limits<int>::min();
    int max_ending_here = 0;
    for (int i = 0; i < n * k; ++i) {
        max_ending_here += a[i % n];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    return {max_so_far, 0}; // The second value is 0 as it was not defined in the original code
}
