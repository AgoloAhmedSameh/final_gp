#include <vector>
#include <algorithm>
#include <iostream>

std::pair<int, int> max_subarray_product(const std::vector<int>& arr) {
    int n = arr.size();
    int max_ending_here = 1;
    int min_ending_here = 1;
    int max_so_far = 0;
    bool flag = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            max_ending_here *= arr[i];
            min_ending_here = std::min(min_ending_here * arr[i], 1);
            flag = true;
        } else if (arr[i] == 0) {
            max_ending_here = 1;
            min_ending_here = 1;
        } else {
            int temp = max_ending_here;
            max_ending_here = std::max(min_ending_here * arr[i], 1);
            min_ending_here = temp * arr[i];
        }
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
    }

    if (!flag && max_so_far == 0) {
        return {0, 0};
    }
    return {max_so_far, 0};
}
