#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

std::pair<std::string, int> max_aggregate(const std::vector<std::pair<std::string, int>>& stdata) {
    std::unordered_map<std::string, int> temp;
    for (const auto& entry : stdata) {
        temp[entry.first] += entry.second;
    }
    return *std::max_element(temp.begin(), temp.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
}
