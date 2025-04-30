#include <vector>

std::pair<std::vector<int>, std::vector<int>> count_duplic(const std::vector<int>& lists) {
    std::vector<int> element;
    std::vector<int> frequency;
    
    if (lists.empty()) {
        return {element, frequency};
    }
    
    int running_count = 1;
    for (size_t i = 0; i < lists.size() - 1; ++i) {
        if (lists[i] == lists[i + 1]) {
            running_count++;
        } else {
            frequency.push_back(running_count);
            element.push_back(lists[i]);
            running_count = 1;
        }
    }
    
    frequency.push_back(running_count);
    element.push_back(lists.back());
    
    return {element, frequency};
}
