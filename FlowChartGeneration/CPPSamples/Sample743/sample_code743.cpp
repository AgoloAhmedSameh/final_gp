#include <vector>
#include <algorithm>

std::pair<bool> check_none(const std::vector<std::any>& test_tup) {
    bool res = std::any_of(test_tup.begin(), test_tup.end(), [](const std::any& ele) { return ele.has_value() == false; });
    return std::make_pair(res);
}
