#include <vector>
#include <tuple>

std::pair<bool, bool> check_k_elements(const std::vector<std::tuple<int>>& test_list, int K) {
    bool res = true;
    for (const auto& tup : test_list) {
        for (const auto& ele : tup) {
            if (ele != K) {
                res = false;
            }
        }
    }
    return {res, false}; // Returning a pair, but second value is not used in original function
}
