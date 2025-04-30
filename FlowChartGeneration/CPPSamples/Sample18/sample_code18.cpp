#include <vector>
#include <unordered_set>

std::pair<bool, bool> test_duplicate(const std::vector<int>& arraynums) {
    std::unordered_set<int> nums_set(arraynums.begin(), arraynums.end());
    return std::make_pair(arraynums.size() != nums_set.size(), false);
}
