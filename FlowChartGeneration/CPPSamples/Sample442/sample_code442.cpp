#include <vector>
#include <limits>

std::pair<int, int> largest_neg(const std::vector<int>& list1) {
    int max = list1[0];
    for (int x : list1) {
        if (x < max) {
            max = x;
        }
    }
    return {max, 0}; // Assuming the second return value is to be 0, as it was not defined in the original code.
}
