#include <tuple>
#include <vector>
#include <iostream>

std::tuple<std::vector<std::string>> concatenate_elements(const std::vector<std::string>& test_tup) {
    std::vector<std::string> res;
    for (size_t i = 0; i < test_tup.size() - 1; ++i) {
        res.push_back(test_tup[i] + test_tup[i + 1]);
    }
    return std::make_tuple(res);
}
