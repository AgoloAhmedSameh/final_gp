#include <vector>
#include <set>
#include <algorithm>

std::pair<bool, std::vector<int>> same_order(const std::vector<int>& l1, const std::vector<int>& l2) {
    std::set<int> common_elements;
    for (int e : l1) {
        if (std::find(l2.begin(), l2.end(), e) != l2.end()) {
            common_elements.insert(e);
        }
    }
    std::vector<int> filtered_l1, filtered_l2;
    for (int e : l1) {
        if (common_elements.count(e)) {
            filtered_l1.push_back(e);
        }
    }
    for (int e : l2) {
        if (common_elements.count(e)) {
            filtered_l2.push_back(e);
        }
    }
    return {filtered_l1 == filtered_l2, filtered_l1}; 
}
