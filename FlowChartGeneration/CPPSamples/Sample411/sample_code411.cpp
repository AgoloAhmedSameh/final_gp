#include <vector>

std::pair<std::vector<int>, std::vector<int>> remove_odd(std::vector<int>& l) {
    for (auto it = l.begin(); it != l.end();) {
        if (*it % 2 != 0) {
            it = l.erase(it);
        } else {
            ++it;
        }
    }
    return {l, {}};
}
