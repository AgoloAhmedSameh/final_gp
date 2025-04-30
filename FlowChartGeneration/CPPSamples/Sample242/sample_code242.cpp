#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <tuple>

std::vector<std::tuple<int, int, int>> sort_on_occurrence(const std::vector<std::pair<int, int>>& lst) {
    std::unordered_map<int, std::vector<int>> dct;

    for (const auto& pair : lst) {
        dct[pair.first].push_back(pair.second);
    }

    std::vector<std::tuple<int, int, int>> result;
    for (const auto& item : dct) {
        std::set<int> unique_items(item.second.begin(), item.second.end());
        result.emplace_back(item.first, unique_items.size(), item.second.size());
    }
    return result;
}
