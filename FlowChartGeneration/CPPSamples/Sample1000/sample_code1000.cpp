#include <vector>
#include <unordered_map>

std::vector<int> remove_duplicates(const std::vector<int>& numbers) {
    std::unordered_map<int, int> c;
    for (int n : numbers) {
        c[n]++;
    }
    std::vector<int> result;
    for (int n : numbers) {
        if (c[n] <= 1) {
            result.push_back(n);
        }
    }
    return result;
}
