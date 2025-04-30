#include <vector>
#include <set>

std::pair<long long, std::vector<int>> unique_product(const std::vector<int>& list_data) {
    std::set<int> unique_set(list_data.begin(), list_data.end());
    long long p = 1;
    for (int i : unique_set) {
        p *= i;
    }
    return {p, std::vector<int>(unique_set.begin(), unique_set.end())};
}
