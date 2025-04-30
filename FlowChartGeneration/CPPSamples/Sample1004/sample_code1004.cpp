#include <vector>

std::vector<int> get_positive(const std::vector<int>& l) {
    std::vector<int> result;
    for (int e : l) {
        if (e > 0) {
            result.push_back(e);
        }
    }
    return result;
}
