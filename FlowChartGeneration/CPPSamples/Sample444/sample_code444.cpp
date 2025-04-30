#include <tuple>
#include <vector>

std::vector<std::vector<int>> index_multiplication(const std::vector<std::vector<int>>& test_tup1, const std::vector<std::vector<int>>& test_tup2) {
    std::vector<std::vector<int>> res;
    for (size_t i = 0; i < test_tup1.size(); ++i) {
        std::vector<int> temp;
        for (size_t j = 0; j < test_tup1[i].size(); ++j) {
            temp.push_back(test_tup1[i][j] * test_tup2[i][j]);
        }
        res.push_back(temp);
    }
    return res;
}
