#include <tuple>
#include <vector>

bool check_smaller(const std::vector<int>& test_tup1, const std::vector<int>& test_tup2) {
    bool res = true;
    for(size_t i = 0; i < test_tup1.size(); ++i) {
        if (test_tup1[i] <= test_tup2[i]) {
            res = false;
            break;
        }
    }
    return res;
}
