#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

std::map<int, int> sort_dict_item(const std::map<int, int>& test_dict) {
    std::vector<std::pair<int, int>> items(test_dict.begin(), test_dict.end());
    std::sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        return (a.second * a.first) < (b.second * b.first);
    });
    
    std::map<int, int> res;
    for (const auto& item : items) {
        res[item.first] = item.second;
    }
    
    return res;
}
