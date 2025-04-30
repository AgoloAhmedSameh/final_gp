#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

std::pair<std::string, std::vector<std::pair<int, int>>> assign_freq(const std::vector<int>& test_list) {
    std::unordered_map<int, int> freq_map;
    for (int num : test_list) {
        freq_map[num]++;
    }
    
    std::vector<std::pair<int, int>> res;
    for (const auto& pair : freq_map) {
        res.emplace_back(pair.first, pair.second);
    }
    
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < res.size(); ++i) {
        oss << "(" << res[i].first << ", " << res[i].second << ")";
        if (i < res.size() - 1) {
            oss << ", ";
        }
    }
    oss << "]";
    
    return {oss.str(), res};
}
