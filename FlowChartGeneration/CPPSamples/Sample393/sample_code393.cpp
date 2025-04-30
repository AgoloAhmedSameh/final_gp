#include <set>
#include <tuple>
#include <vector>

std::pair<bool> check_distinct(const std::vector<int>& test_tup) {
    bool res = true;
    std::set<int> temp;
    for (const auto& ele : test_tup) {
        if (temp.find(ele) != temp.end()) {
            res = false;
            break;
        }
        temp.insert(ele);
    }
    return std::make_pair(res);
}
