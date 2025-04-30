#include <vector>

std::vector<int> remove_empty(const std::vector<int>& list1) {
    std::vector<int> remove_empty;
    for (auto x : list1) {
        if (x) {
            remove_empty.push_back(x);
        }
    }
    return remove_empty;
}
