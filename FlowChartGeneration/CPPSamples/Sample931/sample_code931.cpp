#include <vector>

std::pair<std::vector<int>, std::vector<int>> remove_duplic_list(const std::vector<int>& l) {
    std::vector<int> temp;
    for (int x : l) {
        if (std::find(temp.begin(), temp.end(), x) == temp.end()) {
            temp.push_back(x);
        }
    }
    return {temp};
}
