#include <vector>
#include <tuple>
#include <algorithm>

std::vector<std::vector<int>> merge(const std::vector<std::vector<int>>& lst) {
    std::vector<std::vector<int>> result;
    if (lst.empty()) return result;

    size_t numberOfRows = lst.size();
    size_t numberOfCols = lst[0].size();
    result.resize(numberOfCols, std::vector<int>(numberOfRows));

    for (size_t j = 0; j < numberOfCols; ++j) {
        for (size_t i = 0; i < numberOfRows; ++i) {
            result[j][i] = lst[i][j];
        }
    }

    return result;
}
