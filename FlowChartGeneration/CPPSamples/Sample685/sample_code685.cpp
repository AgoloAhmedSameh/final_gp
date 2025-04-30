#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

std::pair<std::string, std::unordered_map<int, int>> freq_element(const std::vector<int>& test_tup) {
    std::unordered_map<int, int> res;
    for (int ele : test_tup) {
        res[ele] += 1;
    }
    
    std::string result = "{";
    for (auto it = res.begin(); it != res.end(); ++it) {
        result += std::to_string(it->first) + ": " + std::to_string(it->second);
        if (std::next(it) != res.end()) {
            result += ", ";
        }
    }
    result += "}";
    
    return {result, res};
}
