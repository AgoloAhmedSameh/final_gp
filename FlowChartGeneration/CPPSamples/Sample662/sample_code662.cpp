#include <iostream>
#include <limits>

std::pair<int, int> find_max_val(int n, int x, int y) {
    int ans = -std::numeric_limits<int>::max();
    for (int k = 0; k <= n; ++k) {
        if (k % x == y) {
            ans = std::max(ans, k);
        }
    }
    return (ans >= 0 && ans <= n) ? std::make_pair(ans, 0) : std::make_pair(-1, 0);
}
