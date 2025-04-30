#include <vector>

std::pair<int, int> multiple_tuple(const std::vector<int>& nums) {
    std::vector<int> temp(nums);
    int product = 1; 
    for (int x : temp) {
        product *= x;
    }
    return {product, product}; // Assuming the second return value is also product based on the Python function structure
}
