#include <vector>

std::pair<std::vector<int>, std::vector<int>> Split(const std::vector<int>& list) {
    std::vector<int> ev_li;
    for (int i : list) {
        if (i % 2 == 0) {
            ev_li.push_back(i);
        }
    }
    return {ev_li}; 
}
