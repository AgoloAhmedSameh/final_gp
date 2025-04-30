#include <vector>
#include <algorithm>

std::vector<int> sort_array(const std::vector<int>& array) {
    if (array.empty()) {
        return {};
    }
    std::vector<int> sorted_array = array;
    bool reverse_sort = (array[0] + array[array.size() - 1]) % 2 == 0;
    std::sort(sorted_array.begin(), sorted_array.end(), [reverse_sort](int a, int b) {
        return reverse_sort ? a > b : a < b;
    });
    return sorted_array;
}
