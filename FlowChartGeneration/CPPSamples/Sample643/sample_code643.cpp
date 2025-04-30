#include <vector>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> reverse_Array_Upto_K(const std::vector<int>& input, int k) {
    std::vector<int> reversed(input.begin(), input.begin() + k);
    std::reverse(reversed.begin(), reversed.end());
    std::vector<int> remaining(input.begin() + k, input.end());
    reversed.insert(reversed.end(), remaining.begin(), remaining.end());
    return {reversed, remaining};
}
