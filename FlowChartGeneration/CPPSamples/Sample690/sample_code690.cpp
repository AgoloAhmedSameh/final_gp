#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::map<int, std::vector<int>> group_element(const std::vector<std::pair<int, int>>& test_list) {
    std::map<int, std::vector<int>> res;
    std::vector<std::pair<int, int>> sorted_list = test_list;
    
    std::sort(sorted_list.begin(), sorted_list.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    for (const auto& key_val : sorted_list) {
        res[key_val.second].push_back(key_val.first);
    }

    return res;
}
