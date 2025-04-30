#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

std::vector<std::pair<char, int>> most_common_elem(const std::string& s, int a) {
    std::unordered_map<char, int> counter;
    for (char c : s) {
        counter[c]++;
    }
    
    std::vector<std::pair<char, int>> most_common(counter.begin(), counter.end());
    std::sort(most_common.begin(), most_common.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second > rhs.second;
    });
    
    if (a > most_common.size()) {
        a = most_common.size();
    }
    
    most_common.resize(a);
    return most_common;
}
