#include <tuple>
#include <vector>
#include <algorithm>

std::pair<bool> check_tuples(const std::vector<int>& test_tuple, const std::vector<int>& K) {
    bool res = std::all_of(test_tuple.begin(), test_tuple.end(), [&K](int ele) {
        return std::find(K.begin(), K.end(), ele) != K.end();
    });
    return std::make_pair(res);
}
