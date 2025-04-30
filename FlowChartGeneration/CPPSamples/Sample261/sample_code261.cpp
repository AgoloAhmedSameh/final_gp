#include <vector>

std::pair<std::vector<int>, std::vector<int>> split_two_parts(const std::vector<int>& list1, int L) {
    return {std::vector<int>(list1.begin(), list1.begin() + L), std::vector<int>(list1.begin() + L, list1.end())};
}
