#include <vector>
#include <numeric>

int sum_squares(const std::vector<int>& lst) {
    std::vector<int> result;
    for (size_t i = 0; i < lst.size(); ++i) {
        if (i % 3 == 0) {
            result.push_back(lst[i] * lst[i]);
        } else if (i % 4 == 0 && i % 3 != 0) {
            result.push_back(lst[i] * lst[i] * lst[i]);
        } else {
            result.push_back(lst[i]);
        }
    }
    return std::accumulate(result.begin(), result.end(), 0);
}
