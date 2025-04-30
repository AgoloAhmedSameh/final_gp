#include <vector>

bool below_threshold(const std::vector<int>& l, int t) {
    for (int e : l) {
        if (e >= t) {
            return false;
        }
    }
    return true;
}
