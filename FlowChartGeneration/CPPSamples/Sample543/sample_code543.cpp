#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::pair<std::string> flatten_tuple(const std::vector<std::tuple<int, int>>& test_list) {
    std::ostringstream oss;
    for (const auto& tup : test_list) {
        oss << std::get<0>(tup) << ' ' << std::get<1>(tup) << ' ';
    }
    std::string res = oss.str();
    return std::make_pair(res);
}
