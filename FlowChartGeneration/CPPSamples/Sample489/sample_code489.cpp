#include <iostream>
#include <set>
#include <vector>
#include <utility>

std::pair<std::set<std::pair<int, int>>, std::set<std::pair<int, int>>> extract_symmetric(const std::vector<std::pair<int, int>>& test_list) {
    std::set<std::pair<int, int>> temp;
    std::set<std::pair<int, int>> res;

    for (const auto& p : test_list) {
        temp.insert(p);
        temp.insert(std::make_pair(p.second, p.first));
    }

    for (const auto& p : temp) {
        if (p.first < p.second) {
            res.insert(p);
        }
    }
    
    return {res};
}
