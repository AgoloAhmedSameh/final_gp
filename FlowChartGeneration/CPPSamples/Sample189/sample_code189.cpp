#include <utility>

std::pair<int, int> count_Intgral_Points(int x1, int y1, int x2, int y2) {
    return std::make_pair((y2 - y1 - 1) * (x2 - x1 - 1), 0);
}
