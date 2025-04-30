#include <vector>

std::vector<int> insert_element(const std::vector<int>& list, int element) {
    std::vector<int> new_list;
    for (const auto& elt : list) {
        new_list.push_back(element);
        new_list.push_back(elt);
    }
    return new_list;
}
