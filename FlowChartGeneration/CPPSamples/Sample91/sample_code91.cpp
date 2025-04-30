#include <vector>

bool is_undulating(const std::vector<int>& n) {
    if (n.size() <= 2) {
        return false;
    }
    for (size_t i = 2; i < n.size(); i++) {
        if (n[i - 2] != n[i]) {
            return false;
        }
    }
    return true;
}
