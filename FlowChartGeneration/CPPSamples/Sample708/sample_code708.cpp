#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>

std::pair<std::string, std::unordered_map<int, int>> get_unique(const std::vector<std::pair<int, int>>& test_list) {
    std::unordered_map<int, std::vector<int>> res;

    for (const auto& sub : test_list) {
        res[sub.second].push_back(sub.first);
    }

    std::unordered_map<int, int> res_dict;
    for (const auto& pair : res) {
        std::set<int> unique_elements(pair.second.begin(), pair.second.end());
        res_dict[pair.first] = unique_elements.size();
    }

    std::ostringstream oss;
    for (const auto& pair : res_dict) {
        oss << pair.first << ":" << pair.second << " ";
    }

    return {oss.str(), res_dict};
}
