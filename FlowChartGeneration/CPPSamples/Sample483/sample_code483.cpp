#include <iostream>
#include <vector>
#include <algorithm>

std::pair<std::vector<std::tuple<>>, std::vector<std::tuple<>>> remove_matching_tuple(const std::vector<std::tuple<>>& test_list1, const std::vector<std::tuple<>>& test_list2) {
    std::vector<std::tuple<>> res;
    for (const auto& sub : test_list1) {
        if (std::find(test_list2.begin(), test_list2.end(), sub) == test_list2.end()) {
            res.push_back(sub);
        }
    }
    return {res};
}
