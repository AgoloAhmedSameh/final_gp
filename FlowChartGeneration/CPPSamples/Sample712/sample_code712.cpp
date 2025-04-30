#include <tuple>
#include <algorithm>

std::pair<bool> check_valid(const std::tuple<bool, bool>& test_tup) {
    bool res = std::none_of(std::begin(test_tup), std::end(test_tup), [](bool ele) { return !ele; });
    return std::make_pair(res);
}
