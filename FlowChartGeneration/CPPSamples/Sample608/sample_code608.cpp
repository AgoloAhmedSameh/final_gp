#include <algorithm>

std::pair<int, int> floor_Min(int A, int B, int N) {
    int x = std::max(B - 1, N);
    return std::make_pair((A * x) / B, 0);
}
