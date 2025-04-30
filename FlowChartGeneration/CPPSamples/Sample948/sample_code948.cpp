#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int count_digs(const std::vector<int>& tup) {
    int total_length = 0;
    for (int ele : tup) {
        total_length += std::to_string(ele).length();
    }
    return total_length;
}

std::string sort_list(std::vector<int>& test_list) {
    std::sort(test_list.begin(), test_list.end(), [](int a, int b) {
        return count_digs(std::vector<int>{a}) < count_digs(std::vector<int>{b});
    });
    std::string result = "[";
    for (size_t i = 0; i < test_list.size(); ++i) {
        result += std::to_string(test_list[i]);
        if (i < test_list.size() - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}
