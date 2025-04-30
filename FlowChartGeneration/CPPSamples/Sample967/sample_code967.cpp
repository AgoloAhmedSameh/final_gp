#include <algorithm>

std::pair<int, int> floor_Max(int A, int B, int N) {
    int x = std::min(B - 1, N);
    return { (A * x) / B, 0 }; // The second value is kept as 0 for consistency with the original function
}
