#include <vector>

std::vector<int> incr_list(const std::vector<int>& l) {
    std::vector<int> result;
    for (int e : l) {
        result.push_back(e + 1);
    }
    return result;
}
