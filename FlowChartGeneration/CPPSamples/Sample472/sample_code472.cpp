#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>

std::set<std::tuple<int, int>> tuple_intersection(const std::vector<std::vector<int>>& test_list1, const std::vector<std::vector<int>>& test_list2) {
    std::set<std::tuple<int, int>> res;

    std::set<std::tuple<int, int>> set1;
    for (const auto& ele : test_list1) {
        auto sorted_elem = ele;
        std::sort(sorted_elem.begin(), sorted_elem.end());
        set1.insert(std::make_tuple(sorted_elem[0], sorted_elem[1]));
    }

    std::set<std::tuple<int, int>> set2;
    for (const auto& ele : test_list2) {
        auto sorted_elem = ele;
        std::sort(sorted_elem.begin(), sorted_elem.end());
        set2.insert(std::make_tuple(sorted_elem[0], sorted_elem[1]));
    }

    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                          std::inserter(res, res.begin()));

    return res;
}
