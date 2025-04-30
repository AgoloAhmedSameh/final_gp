#include <iostream>
#include <vector>
#include <algorithm>

std::pair<std::string, int> count_reverse_pairs(const std::vector<std::string>& test_list) {
    int res = 0;
    for (size_t idx = 0; idx < test_list.size(); ++idx) {
        for (size_t idxn = idx; idxn < test_list.size(); ++idxn) {
            std::string reversed_str = std::string(test_list[idx].rbegin(), test_list[idx].rend());
            if (test_list[idxn] == reversed_str) {
                res++;
            }
        }
    }
    return {std::to_string(res), res};
}
