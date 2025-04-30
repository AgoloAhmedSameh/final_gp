#include <iostream>
#include <vector>
#include <unordered_map>

std::pair<int, int> max_occurrences(const std::vector<int>& list1) {
    int max_val = 0;
    int result = list1[0];
    std::unordered_map<int, int> count;

    for (int i : list1) {
        count[i]++;
    }

    for (const auto& pair : count) {
        if (pair.second > max_val) {
            max_val = pair.second;
            result = pair.first;
        }
    }
    
    return {result, max_val};
}
