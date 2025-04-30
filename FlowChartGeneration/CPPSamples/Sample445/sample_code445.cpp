#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_set>

std::pair<int, int> count_Occurrence(const std::tuple<int, int, int>& tup, const std::vector<int>& lst) {
    int count = 0;
    std::unordered_set<int> lstSet(lst.begin(), lst.end());
    
    if (std::get<0>(tup) && lstSet.count(std::get<0>(tup))) count++;
    if (std::get<1>(tup) && lstSet.count(std::get<1>(tup))) count++;
    if (std::get<2>(tup) && lstSet.count(std::get<2>(tup))) count++;
    
    return {count, 0}; // second element is 0 as there was no information about it in the original code
}
