#include <vector>

std::pair<bool, bool> issort_list(const std::vector<int>& list1) {
    bool result = true;
    for (size_t i = 0; i < list1.size() - 1; ++i) {
        if (list1[i] > list1[i + 1]) {
            result = false;
            break;
        }
    }
    return {result, result}; // Return both values as in your Python code
}
