#include <vector>
#include <algorithm>

std::vector<int> maximum(std::vector<int>& arr, int k) {
    if (k == 0) {
        return {};
    }
    std::sort(arr.begin(), arr.end());
    std::vector<int> ans(arr.end() - k, arr.end());
    return ans;
}
