#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

int next_smallest(std::vector<int> lst) {
    std::set<int> unique_elements(lst.begin(), lst.end());
    std::vector<int> sorted_lst(unique_elements.begin(), unique_elements.end());

    return sorted_lst.size() < 2 ? -1 : sorted_lst[1]; // Return -1 instead of None for C++
}
