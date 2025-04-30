#include <vector>

int max_element(const std::vector<int>& l) {
    int m = l[0];
    for (const auto& e : l) {
        if (e > m) {
            m = e;
        }
    }
    return m;
}
