#include <tuple>
#include <vector>
#include <string>

std::tuple<std::vector<std::string>> new_tuple(const std::vector<std::string>& test_list, const std::string& test_str) {
    std::vector<std::string> res = test_list;
    res.push_back(test_str);
    return std::make_tuple(res);
}
