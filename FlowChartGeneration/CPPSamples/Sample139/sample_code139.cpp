#include <vector>
#include <set>

std::pair<std::vector<int>, std::set<int>> extract_singly(const std::vector<std::vector<int>>& test_list) {
    std::vector<int> res;
    std::set<int> temp;
    for (const auto& inner : test_list) {
        for (const auto& ele : inner) {
            if (temp.find(ele) == temp.end()) {
                temp.insert(ele);
                res.push_back(ele);
            }
        }
    }
    return {res, temp};
}
