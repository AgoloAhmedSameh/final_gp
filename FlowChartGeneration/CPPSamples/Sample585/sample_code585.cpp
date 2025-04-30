#include <vector>

std::pair<std::vector<int>, std::vector<int>> split_Arr(const std::vector<int>& a, int n, int k) {
    std::vector<int> b(a.begin(), a.begin() + k);
    std::vector<int> result(a.begin() + k, a.end());
    result.insert(result.end(), b.begin(), b.end());
    return {result, {}};
}
