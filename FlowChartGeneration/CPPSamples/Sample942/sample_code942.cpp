#include <vector>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> combine_lists(const std::vector<int>& num1, const std::vector<int>& num2) {
    std::vector<int> combined;
    std::merge(num1.begin(), num1.end(), num2.begin(), num2.end(), std::back_inserter(combined));
    return {combined};
}
