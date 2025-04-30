#include <vector>
#include <algorithm>
#include <iterator>

std::pair<std::vector<int>, std::vector<int>> exchange_elements(const std::vector<int>& lst) {
    std::vector<int> lst1, lst2;
    for (size_t i = 0; i < lst.size(); i += 2) {
        if (i + 1 < lst.size()) {
            lst1.push_back(lst[i + 1]);
        }
        lst2.push_back(lst[i]);
    }
    return {lst1, lst2};
}
