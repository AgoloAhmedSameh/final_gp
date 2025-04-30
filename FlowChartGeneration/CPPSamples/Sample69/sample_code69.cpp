#include <iostream>
#include <vector>
#include <tuple>

int find_equal_tuple(const std::vector<std::tuple<int, int>>& Input, int k) {
    int flag = 1;
    for (const auto& tuple : Input) {
        if (std::tuple_size<decltype(tuple)>::value != k) {
            flag = 0;
            break;
        }
    }
    return flag;
}

std::string get_equal(const std::vector<std::tuple<int, int>>& Input, int k) {
    if (find_equal_tuple(Input, k) == 1) {
        return "All tuples have same length";
    } else {
        return "All tuples do not have same length";
    }
}
