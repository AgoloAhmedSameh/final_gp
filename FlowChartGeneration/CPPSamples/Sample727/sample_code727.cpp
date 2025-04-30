#include <vector>

std::pair<std::vector<int>, std::vector<int>> sum_list(const std::vector<int>& lst1, const std::vector<int>& lst2) {
    std::vector<int> res_list(lst1.size());
    for (size_t i = 0; i < lst1.size(); ++i) {
        res_list[i] = lst1[i] + lst2[i];
    }
    return {res_list, {}};
}
