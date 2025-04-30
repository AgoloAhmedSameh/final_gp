#include <vector>

std::pair<std::vector<int>, std::vector<int>> Split(const std::vector<int>& list) {
    std::vector<int> od_li;
    for (int i : list) {
        if (i % 2 != 0) {
            od_li.push_back(i);
        }
    }
    return {od_li};
}
