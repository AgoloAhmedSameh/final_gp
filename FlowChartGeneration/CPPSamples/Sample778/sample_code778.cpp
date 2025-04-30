#include <iostream>
#include <vector>
#include <map>
#include <tuple>

std::pair<std::map<std::tuple<int, int>, int>, std::map<std::tuple<int, int>, int>> unique_sublists(const std::vector<std::vector<int>>& list1) {
    std::map<std::tuple<int, int>, int> result;
    
    for (const auto& l : list1) {
        std::tuple<int, int> key(l[0], l[1]); // Assuming the sublists have exactly 2 elements
        result[key]++;
    }

    return {result, result};
}
