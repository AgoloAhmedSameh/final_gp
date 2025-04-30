#include <vector>
#include <list>
#include <algorithm>

std::vector<std::vector<int>> pack_consecutive_duplicates(const std::vector<int>& list1) {
    std::vector<std::vector<int>> result;
    if (list1.empty()) return result;

    std::vector<int> current_group;
    current_group.push_back(list1[0]);

    for (size_t i = 1; i < list1.size(); ++i) {
        if (list1[i] == list1[i - 1]) {
            current_group.push_back(list1[i]);
        } else {
            result.push_back(current_group);
            current_group.clear();
            current_group.push_back(list1[i]);
        }
    }
    result.push_back(current_group);
    
    return result;
}
