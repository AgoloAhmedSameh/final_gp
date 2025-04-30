#include <iostream>
#include <tuple>
#include <string>

std::pair<std::string> concatenate_tuple(const std::tuple<int, int, int>& test_tup) {
    std::string delim = "-";
    std::string res;
    
    bool first = true;
    std::apply([&](auto&&... ele) {
        ((first ? first = false : res += delim), (res += std::to_string(ele)), ...);
    }, test_tup);
    
    return std::make_pair(res);
}
