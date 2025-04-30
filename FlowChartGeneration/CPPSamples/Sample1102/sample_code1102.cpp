#include <vector>
#include <numeric>

int prod_signs(const std::vector<int>& arr) {
    if (arr.empty()) return 0;
    bool has_zero = std::find(arr.begin(), arr.end(), 0) != arr.end();
    int prod = has_zero ? 0 : (std::count_if(arr.begin(), arr.end(), [](int x) { return x < 0; }) % 2 == 0 ? 1 : -1);
    return prod * std::accumulate(arr.begin(), arr.end(), 0, [](int sum, int x) { return sum + std::abs(x); });
}
