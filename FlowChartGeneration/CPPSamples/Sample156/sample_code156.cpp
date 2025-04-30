#include <vector>
#include <algorithm>
#include <utility>

std::vector<std::pair<int, int>> encode_list(const std::vector<int>& list1) {
    std::vector<std::pair<int, int>> result;
    if (list1.empty()) return result;

    int count = 1;
    for (size_t i = 1; i <= list1.size(); ++i) {
        if (i < list1.size() && list1[i] == list1[i - 1]) {
            count++;
        } else {
            result.emplace_back(count, list1[i - 1]);
            count = 1;
        }
    }
    return result;
}
