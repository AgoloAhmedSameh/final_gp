#include <vector>

std::pair<bool, bool> check_subset_list(const std::vector<int>& list1, const std::vector<int>& list2) {
    bool exist = true;
    for (int i : list2) {
        if (std::find(list1.begin(), list1.end(), i) == list1.end()) {
            exist = false;
        }
    }
    return {exist, false};
}
