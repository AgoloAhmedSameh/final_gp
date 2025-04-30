#include <tuple>
#include <vector>
#include <string>
#include <iostream>

std::tuple<std::string> concatenate_strings(const std::tuple<std::string>& test_tup1, const std::tuple<std::string>& test_tup2) {
    std::vector<std::string> res;
    for (size_t i = 0; i < std::tuple_size<decltype(test_tup1)>::value; ++i) {
        res.push_back(std::get<i>(test_tup1) + std::get<i>(test_tup2));
    }
    return std::make_tuple(res);
}
