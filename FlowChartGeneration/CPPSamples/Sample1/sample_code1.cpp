#include <iostream>
#include <tuple>
#include <set>
#include <vector>

std::tuple<std::set<int>> similar_elements(const std::vector<int>& test_tup1, const std::vector<int>& test_tup2) {
    std::set<int> set1(test_tup1.begin(), test_tup1.end());
    std::set<int> set2(test_tup2.begin(), test_tup2.end());
    
    std::set<int> res;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(res, res.begin()));
    
    return std::make_tuple(res);
}
