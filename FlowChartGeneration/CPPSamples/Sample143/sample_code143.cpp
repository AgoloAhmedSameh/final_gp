#include <vector>

std::pair<int, int> sum_Pairs(std::vector<int>& arr, int n) {
    int sum = 0;
    for (int i = n - 1; i >= 0; --i) {
        sum += i * arr[i] - (n - 1 - i) * arr[i];
    }
    return {sum, 0}; // Assuming the second return value is 0 as it was not specified in your request
}
