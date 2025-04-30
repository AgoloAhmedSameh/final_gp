#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

std::pair<std::vector<int>, std::vector<int>> extract_unique(const std::map<int, std::vector<int>>& test_dict) {
    std::set<int> unique_elems;
    for (const auto& pair : test_dict) {
        unique_elems.insert(pair.second.begin(), pair.second.end());
    }
    std::vector<int> res(unique_elems.begin(), unique_elems.end());
    std::sort(res.begin(), res.end());
    return {res, {}};
}
