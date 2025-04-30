#include <vector>
#include <string>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> sort_numeric_strings(const std::vector<std::string>& nums_str) {
    std::vector<int> result;
    for (const auto& x : nums_str) {
        result.push_back(std::stoi(x));
    }
    std::sort(result.begin(), result.end());
    return {result, {}};
}
