#include <vector>
#include <algorithm>
#include <utility>

std::pair<int, int> adjacent_num_product(const std::vector<int>& list_nums) {
    int max_product = 0;
    for (size_t i = 0; i < list_nums.size() - 1; ++i) {
        max_product = std::max(max_product, list_nums[i] * list_nums[i + 1]);
    }
    return max_product;
}
