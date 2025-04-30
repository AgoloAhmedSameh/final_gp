#include <tuple>
#include <algorithm>

std::tuple<std::pair<int, int>, std::pair<int, int>> find_Points(int l1, int r1, int l2, int r2) {
    int x = (l1 != l2) ? std::min(l1, l2) : -1;
    int y = (r1 != r2) ? std::max(r1, r2) : -1;
    return {{x, y}};
}
